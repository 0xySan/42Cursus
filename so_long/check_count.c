/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:00:16 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 19:44:15 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_count_all(t_init_map *data, int i, int j)
{
	if (data->map[i][j] == '1')
		return (0);
	if (data->map[i][j] == '0')
		return (0);
	if (data->map[i][j] == 'C')
		return (data->collectable++, 0);
	if (data->map[i][j] == 'P')
		return (0);
	if (data->map[i][j] == 'E')
		return (data->exit++, 0);
	return (1);
}

int	ft_check_bordr(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->length)
		if (data->map[i++][j] != '1')
			return (1);
	j++;
	i = 0;
	while (j < (data->height - 1))
	{
		if(data->map[i][j] != '1' || data->map[data->length - 1][j] != '1')
			return (1);
		j++;
	}
	while (i < data->length)
		if (data->map[i++][j] != '1')
			return (1);
	return (0);
}

int	ft_check_count(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->length)
	{
		j = 0;
		while (j < data->height)
		{
			if (ft_count_all(data, i, j++))
				return (5);
		}
		i++;
	}
	if (data->collectable < 1)
		return (3);
	if (data->exit != 1)
		return (4);
	if (data->length < data->height)
		return (5);
	if (ft_check_bordr(data))
		return (6);
	return (0);
}
