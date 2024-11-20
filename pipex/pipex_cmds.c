/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/20 16:42:50 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *arg)
{
	char	*cpath;

	cpath = malloc(sizeof(char) * (ft_strlen(CMD_PATH) + ft_strlen(arg) + 1));
	if (!cpath)
		return (NULL);
	ft_strcpy(cpath, CMD_PATH);
	ft_strcat(cpath, arg);
	if (access(cpath, X_OK) == -1)
		return (ft_printf("Error command not found : %s.\n", cpath),
			free(cpath), NULL);
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
		return (free(args), free(cpath), error_exit("Execve error.\n"));
	free(cpath);
	free(args);
}
