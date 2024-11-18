/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:13:40 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/18 11:20:25 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(int argc, char **argv)
{
	if (argc != 5)
		exit(0);
	if (access(argv[1], F_OK) == -1)
		return (ft_printf("pipex: no such file or directory: %s\n",
				argv[1]), exit(0));
}
