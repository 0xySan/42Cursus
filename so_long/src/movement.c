/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:50 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 04:24:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_init_map *data)
{
	if (data->map[data->x][data->y] == '1')
		data->y++;
	else if (data->map[data->x][data->y + 1] == 'C')
		return (ft_replace_old_texture(data, data->x, data->y + 1),
			ft_move_up(data));
	else if (data->map[data->x][data->y] == 'S')
		return (ft_replace_old_texture(data, data->x, data->y + 1),
			ft_printf("Key pressed.\nMoved up\nTotal amount : %d\n",
				++data->step),
			ft_printf("You died.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x, data->y + 1),
			ft_printf("Key pressed.\nMoved up\nTotal amount : %d\n",
				++data->step),
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
	else if (data->map[data->x][data->y] == 'S')
		return (ft_replace_old_texture(data, data->x, data->y - 1),
			ft_printf("Key pressed.\nMoved down\nTotal amount : %d\n",
				++data->step),
			ft_printf("You died.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x, data->y - 1),
			ft_printf("Key pressed.\nMoved down\nTotal amount : %d\n",
				++data->step),
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
	else if (data->map[data->x][data->y] == 'S')
		return (ft_replace_old_texture(data, data->x - 1, data->y),
			ft_printf("Key pressed.\nMoved right\nTotal amount : %d\n",
				++data->step),
			ft_printf("You died.\n"), mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x - 1, data->y),
			ft_printf("Key pressed.\nMoved right\nTotal amount : %d\n",
				++data->step),
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
	else if (data->map[data->x][data->y] == 'S')
		return (ft_replace_old_texture(data, data->x + 1, data->y),
			ft_printf("Key pressed.\nMoved left\nTotal amount : %d\n",
				++data->step),
			ft_printf("You died.\n"), ft_show_numbers(data),
			mlx_close_window(data->mlx));
	else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
		return (ft_replace_old_texture(data, data->x + 1, data->y),
			ft_printf("Key pressed.\nMoved left\nTotal amount : %d\n",
				++data->step),
			ft_printf("You won!\n"), ft_show_numbers(data),
			mlx_close_window(data->mlx));
	else
	{
		ft_printf("Key pressed.\nMoved left\nTotal amount : %d\n",
			++data->step);
		ft_replace_old_texture(data, data->x + 1, data->y);
	}
}

void	ft_do_mvmt(t_init_map *data, int mvmt)
{
	if (mvmt)
	{
		if (mvmt == 1)
		{
			data->last_movement = 0;
			ft_move_up(data);
		}
		else if (mvmt == 2)
		{
			data->last_movement = 1;
			ft_move_down(data);
		}
		else if (mvmt == 3)
		{
			data->last_movement = 2;
			ft_move_left(data);
		}
		else if (mvmt == 4)
		{
			data->last_movement = 3;
			ft_move_right(data);
		}
		ft_show_numbers(data);
	}
}
