/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:56:30 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/25 15:05:35 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_here_doc(t_pipex *pipex, char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		error_exit("Error: Pipe creation failed.\n");
	pipex->infile = fd[0];
	write(STDOUT_FILENO, "here_doc> ", 10);
	line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
	{
		write(STDOUT_FILENO, "here_doc> ", 10);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd[1]);
}

void	child_process(t_pipex *pipex, char *cmd, char **envp, int cmd_idx)
{
	pipex->pid[cmd_idx] = fork();
	if (pipex->pid[cmd_idx] == -1)
		error_exit("Error: Fork failed.\n");
	if (pipex->pid[cmd_idx] == 0)
	{
		if (cmd_idx == 0)
			dup2(pipex->infile, STDIN_FILENO);
		else
			dup2(pipex->pipes[cmd_idx - 1][0], STDIN_FILENO);
		if (cmd_idx == pipex->cmd_count - 1)
			dup2(pipex->outfile, STDOUT_FILENO);
		else
			dup2(pipex->pipes[cmd_idx][1], STDOUT_FILENO);
		close_pipes(pipex);
		execute_cmd(cmd, envp);
	}
}

void	handle_here_doc_mode(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int	i;

	if (argc < 6)
		error_exit("Error.\nUsage: ./pipex here_doc LIMITER cmd cmd1 file\n");
	pipex->cmd_count = argc - 4;
	init_pipes(pipex, pipex->cmd_count);
	handle_here_doc(pipex, argv[2]);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipex->outfile < 0)
		error_exit("Error: Could not open output file.\n");
	i = -1;
	while (++i < pipex->cmd_count)
		child_process(pipex, argv[3 + i], envp, i);
	i = 0;
	close_pipes(pipex);
	while (i < pipex->cmd_count)
		waitpid(pipex->pid[i++], NULL, 0);
	free_pipes(pipex);
}

void	handle_standard_mode(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int	i;

	check_init_sm(argc, argv, pipex);
	init_pipes(pipex, pipex->cmd_count);
	i = -1;
	while (++i < pipex->cmd_count)
		child_process(pipex, argv[2 + i], envp, i);
	i = 0;
	close_pipes(pipex);
	while (i < pipex->cmd_count)
		waitpid(pipex->pid[i++], NULL, 0);
	free_pipes(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		error_exit("Invalid arguments.\nUsage: ./pipex file cmd cmd .. file\n");
	if (ft_strcmp(argv[1], "here_doc") == 0)
		handle_here_doc_mode(argc, argv, envp, &pipex);
	else
		handle_standard_mode(argc, argv, envp, &pipex);
	return (0);
}
