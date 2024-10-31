/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:50:16 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/31 16:30:44 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	isvalid(int row, int col, t_init_map *data)
{
	return (row >= 0 && row < data->length && col >= 0 && col < data->height
		&& data->map[row][col] != '1' && !data->visited[row][col]);
}

void	ft_dfs(int row, int col, t_init_map *data)
{
	int	i;
	int	newrow;
	int	newcol;

	data->visited[row][col] = 1;
	i = 0;
	while (i < 4)
	{
		newrow = row + data->d_row[i];
		newcol = col + data->d_col[i];
		if (isvalid(newrow, newcol, data))
			ft_dfs(newrow, newcol, data);
		i++;
	}
}

int	**ft_initialize_visited(t_init_map *data)
{
	int	i;
	int	j;

	data->visited = malloc(((data->length) * sizeof(int *)));
	i = 0;
	while (i < data->length)
		data->visited[i++] = malloc((data->height) * sizeof(int));
	i = 0;
	while (i < data->length)
	{
		j = 0;
		while (j < data->height)
		{
			data->visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (data->visited);
}

int	ft_dfs_checker(t_init_map *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->length)
	{
		j = -1;
		while (++j < data->height)
		{
			if (data->map[i][j] == 'P')
			{
				data->player++;
				data->x = i;
				data->y = j;
			}
		}
	}
	if (data->player != 1)
		return (1);
	data->visited = ft_initialize_visited(data);
	ft_dfs(data->x, data->y, data);
	return (0);
}

int	ft_map_checker(t_init_map *data)
{
	int		i;
	int		j;

	if (ft_dfs_checker(data))
		return (ft_free_less(data), 2);
	i = -1;
	while (++i < data->length)
	{
		j = -1;
		while (++j < data->height)
		{
			if (data->map[i][j] == 'C' && !data->visited[i][j])
				data->cancollect = 0;
			if (data->map[i][j] == 'E' && data->visited[i][j])
				data->canexit = 1;
		}
	}
	if (data->cancollect && data->canexit)
		return (0);
	return (ft_free_some(data), 1);
}
