/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:35:37 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 15:41:01 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_free_some(t_init_map *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->length)
	{
		j = 0;
		while (j < so_long->height)
		{
			j++;
		}
		free(so_long->map[i]);
		free(so_long->visited[i]);
		i++;
	}
	free(so_long->map);
	free(so_long->visited);
	free(so_long->d_col);
	free(so_long->d_row);
}

void	ft_free_all(t_init_map *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->length)
	{
		j = 0;
		while (j < so_long->height)
		{
			j++;
		}
		free(so_long->map[i]);
		free(so_long->visited[i]);
		i++;
	}
	free(so_long->map);
	free(so_long->visited);
	free(so_long->graph);
	free(so_long->d_col);
	free(so_long->d_row);
}

void	ft_map_data(t_init_map *so_long, char *name)
{
	so_long->height = 0;
	so_long->length = 0;
	so_long->escape = 0;
	so_long->collectable = 0;
	so_long->step = 0;
	so_long->x = 0;
	so_long->y = 0;
	so_long->player = 0;
	so_long->fn = name;
	so_long->d_col = malloc(sizeof(int) * 4);
	so_long->d_col[0] = -1;
	so_long->d_col[1] = 1;
	so_long->d_col[2] = 0;
	so_long->d_col[3] = 0;
	so_long->d_row = malloc(sizeof(int) * 4);
	so_long->d_row[0] = 0;
	so_long->d_row[1] = 0;
	so_long->d_row[2] = -1;
	so_long->d_row[3] = 1;
}
