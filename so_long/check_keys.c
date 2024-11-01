/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:39:09 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/01 15:54:31 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "math.h"

int	ft_move_fh(t_init_map *data, mlx_t *mlx, bool *key_states)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		&& !key_states[0])
	{
		data->y -= 1;
		key_states[0] = true;
		return (1);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_UP)
		&& !mlx_is_key_down(mlx, MLX_KEY_W))
		key_states[0] = false;
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		&& !key_states[1])
	{
		data->y += 1;
		key_states[1] = true;
		return (2);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_DOWN)
		&& !mlx_is_key_down(mlx, MLX_KEY_S))
		key_states[1] = false;
	return (0);
}

int	ft_move_sh(t_init_map *data, mlx_t *mlx, bool *key_states)
{
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		&& !key_states[2])
	{
		data->x -= 1;
		key_states[2] = true;
		return (3);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(mlx, MLX_KEY_A))
		key_states[2] = false;
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		&& !key_states[3])
	{
		data->x += 1;
		key_states[3] = true;
		return (4);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_RIGHT)
		&& !mlx_is_key_down(mlx, MLX_KEY_D))
		key_states[3] = false;
	return (0);
}

int	ft_move(t_init_map *data)
{
	mlx_t		*mlx;
	int			result;
	static bool	key_states[4] = {false, false, false, false};
	// could be useful for enemies that move everytime / animations
	data->animation_index = ((int)round(mlx_get_time() * 6) / 2) % 4;
	printf("%d\n", data->animation_index);
	mlx = data->mlx;
	result = ft_move_fh(data, mlx, key_states);
	if (result)
		return (result);
	result = ft_move_sh(data, mlx, key_states);
	return (result);
}
