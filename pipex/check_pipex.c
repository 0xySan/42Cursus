/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:12:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 12:15:56 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access_f1(char **argv)
{
	if (access(argv[1], F_OK) == -1)
	{
		ft_dprintf(2, "pipex: no such file or directory: %s\n", argv[1]);
		return (1);
	}
	if (access(argv[1], R_OK) == -1)
	{
		ft_dprintf(2, "pipex: permission denied: %s\n", argv[1]);
		return (1);
	}
	return (0);
}

void	check_init_sm(int argc, char **argv, t_pipex *pipex)
{
	int	error;

	error = check_access_f1(argv);
	pipex->cmd_count = argc - 3;
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		if (error)
		{
			ft_dprintf(2, "pipex: permission denied: %s\n", argv[argc - 1]);
			return (exit(EXIT_FAILURE));
		}
		else
		{
			ft_dprintf(2, "pipex: permission denied: %s\n", argv[argc - 1]);
			close(pipex->infile);
			return (exit(EXIT_FAILURE));
		}
	}
	if (error)
	{
		pipex->infile = open("/dev/null", O_RDONLY);
		pipex->error = 1;
	}
}
