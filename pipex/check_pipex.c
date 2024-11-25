/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:12:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/25 13:31:27 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_init_sm(int argc, char **argv, t_pipex *pipex)
{
	int	error;

	error = 0;
	pipex->cmd_count = argc - 3;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		ft_dprintf(2, "pipex: no such file or directory: %s\n", argv[1]);
		error = 1;
	}
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		if (error)
			return (ft_dprintf(2, "pipex: permission denied: %s\n",
					argv[argc - 1]), exit(EXIT_FAILURE));
		else
			return (ft_dprintf(2, "pipex: permission denied: %s\n",
					argv[argc - 1]), close(pipex->infile), exit(EXIT_FAILURE));
	}
	if (error)
		return (close(pipex->outfile), exit(EXIT_FAILURE));
}
