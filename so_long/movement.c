/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:50 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/04 02:36:08 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <math.h>

void	ft_move_up(t_init_map *data)
{
	if (data->map[data->x][data->y] == '1')
		data->y++;
	else if (data->map[data->x][data->y + 1] == 'C')
		return (ft_replace_old_texture(data, data->x, data->y + 1),
			ft_move_up(data));
	else if ((data->map[data->x][data->y] == 'S'))
		return (ft_replace_old_texture(data, data->x, data->y + 1),
			ft_printf("You lost.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x, data->y + 1),
			ft_printf("You won!\n"), mlx_close_window(data->mlx));
	else
	{
		ft_printf("Key pressed.\nMoved up\nTotal amount : %d\n",
			++data->step);
		ft_replace_old_texture(data, data->x, data->y + 1);
	}
}

void	ft_move_down(t_init_map *data)
{
	if (data->map[data->x][data->y] == '1')
		data->y--;
	else if (data->map[data->x][data->y - 1] == 'C')
		return (ft_replace_old_texture(data, data->x, data->y - 1),
			ft_move_down(data));
	else if ((data->map[data->x][data->y] == 'S'))
		return (ft_replace_old_texture(data, data->x, data->y - 1),
			ft_printf("You lost.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x, data->y - 1),
			ft_printf("You won!\n"), mlx_close_window(data->mlx));
	else
	{
		ft_printf("Key pressed.\nMoved down\nTotal amount : %d\n",
			++data->step);
		ft_replace_old_texture(data, data->x, data->y - 1);
	}
}

void	ft_move_right(t_init_map *data)
{
	if (data->map[data->x][data->y] == '1')
		data->x--;
	else if (data->map[data->x - 1][data->y] == 'C')
		return (ft_replace_old_texture(data, data->x - 1, data->y),
			ft_move_right(data));
	else if ((data->map[data->x][data->y] == 'S'))
		return (ft_replace_old_texture(data, data->x - 1, data->y),
			ft_printf("You lost.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x - 1, data->y),
			ft_printf("You won!\n"), mlx_close_window(data->mlx));
	else
	{
		ft_printf("Key pressed.\nMoved right\nTotal amount : %d\n",
			++data->step);
		ft_replace_old_texture(data, data->x - 1, data->y);
	}
}

void	ft_move_left(t_init_map *data)
{
	if (data->map[data->x][data->y] == '1')
		data->x++;
	else if (data->map[data->x + 1][data->y] == 'C')
		return (ft_replace_old_texture(data, data->x + 1, data->y),
			ft_move_left(data));
	else if ((data->map[data->x][data->y] == 'S'))
		return (ft_replace_old_texture(data, data->x + 1, data->y),
			ft_printf("You lost.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x + 1, data->y),
			ft_printf("You won!\n"), mlx_close_window(data->mlx));
	else
	{
		ft_printf("Key pressed.\nMoved left\nTotal amount : %d\n",
			++data->step);
		ft_replace_old_texture(data, data->x + 1, data->y);
	}
}

void	ft_reload_map(t_init_map *data, int mvmt)
{
	xpm_t	*xpm;

	if (mvmt == 1)
	{
		data->last_movement = 0;
		ft_move_up(data);
	}
	if (mvmt == 2)
	{
		data->last_movement = 1;
		ft_move_down(data);
	}
	if (mvmt == 3)
	{
		data->last_movement = 2;
		ft_move_left(data);
	}
	if (mvmt == 4)
	{
		data->last_movement = 3;
		ft_move_right(data);
	}
	data->animation_index = ((int)round(mlx_get_time() * 6) / 2) % 4;
	xpm = mlx_load_xpm42(data->animations[data->last_movement][data->animation_index]);
	data->graph->player = mlx_texture_to_image(data->mlx, &xpm->texture);
	mlx_image_to_window(data->mlx, data->graph->player,
		data->x * 40, data->y * 40);
}
