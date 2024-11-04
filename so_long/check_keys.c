/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:39:09 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/04 02:35:54 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "math.h"

int	ft_move_fh(t_init_map *data, mlx_t *mlx, int *key_states)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		&& !key_states[0])
	{
		data->y -= 1;
		key_states[0] = 1;
		return (1);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_UP)
		&& !mlx_is_key_down(mlx, MLX_KEY_W))
		key_states[0] = 0;
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		&& !key_states[1])
	{
		data->y += 1;
		key_states[1] = 1;
		return (2);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_DOWN)
		&& !mlx_is_key_down(mlx, MLX_KEY_S))
		key_states[1] = 0;
	return (0);
}

int	ft_move_sh(t_init_map *data, mlx_t *mlx, int *key_states)
{
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		&& !key_states[2])
	{
		data->x -= 1;
		key_states[2] = 1;
		return (3);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(mlx, MLX_KEY_A))
		key_states[2] = 0;
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		&& !key_states[3])
	{
		data->x += 1;
		key_states[3] = 1;
		return (4);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_RIGHT)
		&& !mlx_is_key_down(mlx, MLX_KEY_D))
		key_states[3] = 0;
	return (0);
}

int	ft_move(t_init_map *data)
{
	int			result;

	result = ft_move_fh(data, data->mlx, data->key_states);
	if (result)
		return (result);
	result = ft_move_sh(data, data->mlx, data->key_states);
	return (result);
}
