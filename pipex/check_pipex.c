/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:12:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 12:41:26 by etaquet          ###   ########.fr       */
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
			return (ft_dprintf(2, "pipex: permission denied: %s\n",
					argv[argc - 1]), exit(EXIT_FAILURE));
		else
			return (ft_dprintf(2, "pipex: permission denied: %s\n",
					argv[argc - 1]), close(pipex->infile), exit(EXIT_FAILURE));
		error = 2;
	}
	if (error == 2)
		return (close(pipex->outfile), exit(EXIT_FAILURE));
}
