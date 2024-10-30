/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:50:16 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 15:42:39 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "includes/so_long.h"

bool	isvalid(int row, int col, t_init_map *data)
{
	return (row >= 0 && row < data->length && col >= 0 && col < data->height
		&& data->map[row][col] != '1' && !data->visited[row][col]);
}

void	ft_dfs(int row, int col, t_init_map *data)
{
	int	i;
	int	newrow;
	int	newcol;

	data->visited[row][col] = true;
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

bool	**ft_initialize_visited(t_init_map *data)
{
	int	i;
	int	j;

	data->visited = malloc(((data->length) * sizeof(char *)));
	i = 0;
	while (i < data->length)
		data->visited[i++] = malloc((data->height) * sizeof(char));
	i = 0;
	while (i < data->length)
	{
		j = 0;
		while (j < data->height)
		{
			data->visited[i][j] = false;
			j++;
		}
		i++;
	}
	return (data->visited);
}

void	ft_dfs_checker(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->length)
	{
		j = 0;
		while (j < data->height)
		{
			if (data->map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
			}
			j++;
		}
		i++;
	}
	data->visited = ft_initialize_visited(data);
	ft_dfs(data->x, data->y, data);
}

int	ft_map_checker(t_init_map *data)
{
	bool	cancollect;
	bool	canexit;
	int		i;
	int		j;

	ft_dfs_checker(data);
	cancollect = true;
	canexit = false;
	i = 0;
	while (i < data->length)
	{
		j = 0;
		while (j < data->height)
		{
			if (data->map[i][j] == 'C' && !data->visited[i][j])
				cancollect = false;
			if (data->map[i][j] == 'E' && data->visited[i][j])
				canexit = true;
			j++;
		}
		i++;
	}
	if (cancollect && canexit)
		return (0);
	return (1);
}
