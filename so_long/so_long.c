/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/04 09:05:43 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_exit(t_init_map *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

void	ft_reload_map(t_init_map *data, int mvmt)
{
	xpm_t	*xpm;

	ft_do_mvmt(data, mvmt);
	data->animation_index = ((size_t)round(mlx_get_time() * 6) / 2) % 4;
	xpm = mlx_load_xpm42(data
			->animations[data->last_movement][data->animation_index]);
	data->graph->player = mlx_texture_to_image(data->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	mlx_image_to_window(data->mlx, data->graph->player,
		data->x * 40, data->y * 40);
}

void	ft_reload_mvmt(void *data)
{
	int	mvmt;

	mvmt = ft_move(data);
	ft_reload_map(data, mvmt);
}

int	main(int argc, char **argv)
{
	t_init_map	so_long;

	if (argc == 2)
	{
		ft_map_data(&so_long, argv[1]);
		ft_read_map(&so_long);
		so_long.error_type = ft_check_count(&so_long);
		if (so_long.error_type)
			return (ft_printf("Error.\nInvalid count.\nError type : %d\n",
					so_long.error_type), 0);
		so_long.error_type = ft_map_checker(&so_long);
		if (so_long.error_type)
			return (ft_printf("Error.\nInvalid map.\nError type : %d\n",
					so_long.error_type), 0);
		so_long.mlx = mlx_init(so_long.length * 40,
				so_long.height * 40, "So_long", false);
		ft_parse_map(&so_long);
		ft_create_map(&so_long);
		mlx_loop_hook(so_long.mlx, ft_reload_mvmt, &so_long);
		mlx_loop(so_long.mlx);
		mlx_terminate(so_long.mlx);
		ft_free_all(&so_long);
		printf("Exiting the game.\n");
	}
}
