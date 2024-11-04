/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/04 19:45:56 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

int	check_error_type(t_init_map *so_long)
{
	so_long->error_type = ft_check_count(so_long);
	if (so_long->error_type)
		return (ft_printf("Error.\nInvalid cound.\nError type : %d\n",
					so_long->error_type), 1);
	so_long->error_type = ft_map_checker(so_long);
	if (so_long->error_type)
		return (ft_printf("Error.\nInvalid map.\nError type : %d\n",
					so_long->error_type), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_init_map	so_long;
	char		*file_format;

	if (argc == 2)
	{
		file_format = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
		if (memcmp(file_format, ".ber", 4))
			return (free(file_format), ft_printf("Error\nInvalid file format."), -1);
		free(file_format);
		ft_map_data(&so_long, argv[1]);
		ft_read_map(&so_long);
		if (check_error_type(&so_long))
			return (-1);
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
