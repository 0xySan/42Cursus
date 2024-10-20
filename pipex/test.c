/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:56:30 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/20 21:12:37 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "test.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <string.h>
#include <sys/wait.h>

char	*get_cmd_path(char *arg)
{
	char	*cpath;

	cpath = malloc(sizeof(char) * (ft_strlen(CMD_PATH) + ft_strlen(arg) + 1));
	if (!cpath)
		return (0);
	strcpy(cpath, CMD_PATH);
	strcat(cpath, arg);
	printf("%s", cpath);
	if (access(cpath, X_OK) == -1)
	{
		free(cpath);
		printf("error cpath");
		return (0);
	}
	return (cpath);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cpath;

	args = ft_split(cmd, ' ');
	cpath = get_cmd_path(args[0]);
	if (!cpath)
		return ;
	if (execve(cpath, args, envp) == -1)
	{
		free(cpath);
		free(args);
		printf("error");
		return ;
	}
	free(cpath);
	free(args);
}

void	first_child(t_pipex pipex, char **args, char **envp)
{
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		dup2(pipex.infile, STDIN_FILENO);
		dup2(pipex.tube[1], STDOUT_FILENO);
		close(pipex.tube[0]);
		close(pipex.infile);
		close(pipex.outfile);
		execute_cmd(args[2], envp);
	}
}

void	second_child(t_pipex pipex, char **args, char **envp)
{
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
	{
		dup2(pipex.tube[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		close(pipex.tube[1]);
		close(pipex.infile);
		close(pipex.outfile);
		execute_cmd(args[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.pid2 = 0;
	pipex.pid1 = 0;
	if (argc != 5)
		return (0);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		return (0);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		return (0);
	if (pipe(pipex.tube) == -1)
		return (0);
	first_child(pipex, argv, envp);
	second_child(pipex, argv, envp);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	close(pipex.infile);
	close(pipex.outfile);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
