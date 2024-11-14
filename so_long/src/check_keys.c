/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:39:09 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 04:12:32 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_fh(t_init_map *data, mlx_t *mlx)
{
	double	current_time;
	double	move_interval;

	current_time = mlx_get_time();
	move_interval = 0.1;
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		&& (current_time - data->numbr_time >= move_interval))
	{
		data->y -= 1;
		data->numbr_time = current_time;
		return (1);
	}
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		&& (current_time - data->numbr_time >= move_interval))
	{
		data->y += 1;
		data->numbr_time = current_time;
		return (2);
	}
	return (0);
}

int	ft_move_sh(t_init_map *data, mlx_t *mlx)
{
	double	current_time;
	double	move_interval;

	current_time = mlx_get_time();
	move_interval = 0.1;
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		&& (current_time - data->numbr_time >= move_interval))
	{
		data->x -= 1;
		data->numbr_time = current_time;
		return (3);
	}
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		&& (current_time - data->numbr_time >= move_interval))
	{
		data->x += 1;
		data->numbr_time = current_time;
		return (4);
	}
	return (0);
}

int	ft_move(t_init_map *data)
{
	int			result;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	result = ft_move_fh(data, data->mlx);
	if (result)
		return (result);
	result = ft_move_sh(data, data->mlx);
	return (result);
}
