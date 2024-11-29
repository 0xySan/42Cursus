/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/25 15:07:38 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_if_only_space(char *str)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			v++;
			i++;
		}
	}
	return (v);
}

char	*get_cmd_path(char *arg)
{
	char	*cpath;

	cpath = malloc(sizeof(char) * (ft_strlen(CMD_PATH) + ft_strlen(arg) + 1));
	if (!cpath)
		return (NULL);
	ft_strcpy(cpath, CMD_PATH);
	ft_strcat(cpath, arg);
	if (access(cpath, X_OK) == -1)
	{
		ft_dprintf(2, "pipex: command not found: %s\n", arg);
		return (free(cpath), free(arg), NULL);
	}
	return (cpath);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cpath;

	if (check_if_only_space(cmd) == 0 || cmd[0] == ' ')
	{
		ft_dprintf(2, "pipex: permission denied: %s\n", cmd);
		return ;
	}
	args = ft_split(cmd, ' ');
	cpath = get_cmd_path(args[0]);
	if (!cpath)
		return (free(cpath), free(args));
	if (execve(cpath, args, envp) == -1)
		return (free(cpath), ft_dprintf(2, "Execve error.\n"), free(args));
	free(args);
	free(cpath);
}
