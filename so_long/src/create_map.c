/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:26:19 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/13 23:59:41 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_create_img(t_init_map *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_image_to_window(data->mlx, data->graph->wall, i * 40, j * 40);
	else if (data->map[i][j] == 'C')
		mlx_image_to_window(data->mlx, data->graph->collect, i * 40, j * 40);
	else if (data->map[i][j] == 'P')
		mlx_image_to_window(data->mlx, data->graph->player, i * 40, j * 40);
	else if (data->map[i][j] == 'E')
		mlx_image_to_window(data->mlx, data->graph->exit, i * 40, j * 40);
	else if (data->map[i][j] == 'S')
		mlx_image_to_window(data->mlx, data->graph->enemy, i * 40, j * 40);
	else
		mlx_image_to_window(data->mlx, data->graph->empty, i * 40, j * 40);
}

void	ft_create_map(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->length)
	{
		j = 0;
		while (j < data->height)
			ft_create_img(data, i, j++);
		i++;
	}
}

void	ft_replace_old_texture(t_init_map *data, int x, int y)
{
	if (data->map[x][y] == 'C')
	{
		mlx_image_to_window(data->mlx, data->graph->empty, x * 40, y * 40);
		data->collectable--;
		data->map[x][y] = '0';
	}
	else if (data->map[x][y] == 'E')
		mlx_image_to_window(data->mlx, data->graph->exit, x * 40, y * 40);
	else
	{
		mlx_image_to_window(data->mlx, data->graph->empty, x * 40, y * 40);
		data->map[x][y] = '0';
	}
}

void	ft_parse_map(t_init_map *so_long)
{
	xpm_t	*xpm;

	so_long->graph = malloc(sizeof(t_graph));
	xpm = mlx_load_xpm42(UP1);
	so_long->graph->player = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(WALL);
	so_long->graph->wall = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(EMPTY);
	so_long->graph->empty = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(EXIT);
	so_long->graph->exit = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(COLLECT);
	so_long->graph->collect = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(ENEMY);
	so_long->graph->enemy = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	ft_parse_numbers(so_long);
}
