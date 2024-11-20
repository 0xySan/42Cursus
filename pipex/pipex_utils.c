/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:13:40 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/20 16:30:24 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		i++;
	}
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
}

void	free_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	free(pipex->pid);
}

void	init_pipes(t_pipex *pipex, int cmd_count)
{
	int	i;

	pipex->pipes = malloc(sizeof(int *) * (cmd_count - 1));
	pipex->pid = malloc(sizeof(pid_t) * cmd_count);
	if (!pipex->pipes || !pipex->pid)
		error_exit("Error: Memory allocation failed.\n");
	i = 0;
	while (i < cmd_count - 1)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (pipe(pipex->pipes[i]) == -1)
			error_exit("Error: Pipe creation failed.\n");
		i++;
	}
}
