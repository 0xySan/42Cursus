/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:58:14 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 12:15:41 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define CMD_PATH "/bin/"

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_dprintf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		**pipes;
	pid_t	*pid;
	int		cmd_count;
	int		here_doc;
	int		error;
}	t_pipex;

void	execute_cmd(char *cmd, char **envp);
void	close_pipes(t_pipex *pipex);
void	free_pipes(t_pipex *pipex);
void	init_pipes(t_pipex *pipex, int cmd_count);
void	child_process(t_pipex *pipex, char *cmd, char **envp, int cmd_idx);
void	handle_here_doc(t_pipex *pipex, char *limiter);
void	error_exit(char *message);
void	check_init_sm(int argc, char **argv, t_pipex *pipex);

#endif