/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 04:21:16 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_reload_map(t_init_map *data, int mvmt)
{
	xpm_t	*xpm;

	ft_do_mvmt(data, mvmt);
	data->animation_index = ((size_t)(mlx_get_time() * 8) / 2) % 4;
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

void	check_format_type(char **argv)
{
	char		*file_ext;

	file_ext = ft_substr(argv[1],
			ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (ft_memcmp(file_ext, ".ber", 4))
	{
		free(file_ext);
		ft_printf("Error\nFormat usage : [map_file.ber] not [%s]\n", argv[1]);
		exit(11);
	}
	free(file_ext);
}

int	main(int argc, char **argv)
{
	t_init_map	so_long;

	if (argc != 2)
		return (ft_printf("Error\nUsage : ./so_long [map_file.ber]\n"), 10);
	check_format_type(argv);
	ft_map_data(&so_long, argv[1]);
	ft_read_map(&so_long);
	ft_check_count(&so_long);
	ft_map_checker(&so_long);
	so_long.mlx = mlx_init(so_long.length * 40,
			(so_long.height + 1) * 40, "So_long", false);
	ft_parse_map(&so_long);
	ft_create_map(&so_long);
	ft_malloc_numbers(&so_long);
	ft_show_numbers(&so_long);
	mlx_loop_hook(so_long.mlx, ft_reload_mvmt, &so_long);
	mlx_loop(so_long.mlx);
	mlx_terminate(so_long.mlx);
	ft_free_all(&so_long);
	printf("Exiting the game.\n");
	return (0);
}
