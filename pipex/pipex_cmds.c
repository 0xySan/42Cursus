/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 12:03:38 by etaquet          ###   ########.fr       */
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

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

char	**getpath(char **envp)
{
	char	*gpath;
	char	**mpath;
	int		i;

	if (!envp)
		return (NULL);
	i = -1;
	mpath = NULL;
	gpath = NULL;
	while (envp[++i])
		if (!ft_memcmp(envp[i], "PATH=", 5))
			gpath = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	mpath = ft_split(gpath, ':');
	if (gpath)
		free(gpath);
	if (mpath)
		return (mpath);
	return (NULL);
}

char	*get_cmd_path(char *arg, char **envp)
{
	char	*cpath;
	char	**mp;
	int		i;

	i = 0;
	if (access(arg, X_OK) != -1)
		return (arg);
	mp = getpath(envp);
	if (!mp)
		return (NULL);
	while (mp[i])
	{
		cpath = malloc(sizeof(char) * (ft_strlen(mp[i]) + ft_strlen(arg) + 2));
		if (!cpath)
			return (NULL);
		ft_strcpy(cpath, mp[i]);
		ft_strcat(cpath, "/");
		ft_strcat(cpath, arg);
		if (access(cpath, X_OK) != -1)
			return (free_args(mp), cpath);
		free(cpath);
		i++;
	}
	free_args(mp);
	return (NULL);
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
	cpath = get_cmd_path(args[0], envp);
	if (!cpath)
	{
		free_args(args);
		perror("pipex");
		return ;
	}
	if (execve(cpath, args, envp) == -1)
		return (free(cpath), ft_dprintf(2, "Execve error.\n"),
			free_args(args));
}
