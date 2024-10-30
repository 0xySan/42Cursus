/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:32:23 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 02:47:50 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_exit(t_init_map *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

int	ft_move(t_init_map *data)
{
	mlx_t* mlx = data->mlx;
	static bool key_states[4] = {false, false, false, false};

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && !key_states[0])
	{
		data->y -= 1;
		key_states[0] = true;
		return (1);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_UP))
		key_states[0] = false;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) && !key_states[1])
	{
		data->y += 1;
		key_states[1] = true;
		return (2);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_DOWN))
		key_states[1] = false;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) && !key_states[2])
	{
		data->x -= 1;
		key_states[2] = true;
		return (3);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_LEFT))
		key_states[2] = false;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) && !key_states[3])
	{
		data->x += 1;
		key_states[3] = true;
		return (4);
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		key_states[3] = false;
	return (0);
}

void	ft_create_map(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->length)
	{
		while (j < data->height)
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->graph->wall, i * 40, j * 40);
			if (data->map[i][j] == '0')
				mlx_image_to_window(data->mlx, data->graph->empty, i * 40, j * 40);
			if (data->map[i][j] == 'C')
			{
				mlx_image_to_window(data->mlx, data->graph->collect, i * 40, j * 40);
				data->collectable++;
			}
			if (data->map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
				mlx_image_to_window(data->mlx, data->graph->player, i * 40, j * 40);
			}
			if (data->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->graph->exit, i * 40, j * 40);
			j++;
		}
		j = 0, i++;
	}
}

void	ft_replace_old_texture(t_init_map *data, int x, int y)
{
	if (data->map[x][y] == 'E')
		mlx_image_to_window(data->mlx, data->graph->exit, x * 40, y * 40);
	else if (data->map[x][y] == 'C')
	{
		mlx_image_to_window(data->mlx, data->graph->empty, x * 40, y * 40);
		data->collectable--;
		data->map[x][y] = '0';
	}
	else
		mlx_image_to_window(data->mlx, data->graph->empty, x * 40, y * 40);
}

void	ft_reload_map(t_init_map *data, int mvmt)
{
	if (mvmt == 1)
	{
		if (data->map[data->x][data->y] == '1')
			data->y++;
		else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
			mlx_close_window(data->mlx);
		else
			ft_replace_old_texture(data, data->x, data->y + 1);
	}
	if (mvmt == 2)
	{
		if (data->map[data->x][data->y] == '1')
			data->y--;
		else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
			mlx_close_window(data->mlx);
		else
			ft_replace_old_texture(data, data->x, data->y - 1);
	}
	if (mvmt == 3)
	{
		if (data->map[data->x][data->y] == '1')
			data->x++;
		else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
			mlx_close_window(data->mlx);
		else
			ft_replace_old_texture(data, data->x + 1, data->y);
	}
	if (mvmt == 4)
	{
		if (data->map[data->x][data->y] == '1')
			data->x--;
		else if ((data->map[data->x][data->y] == 'E') && (data->collectable == 0))
			mlx_close_window(data->mlx);
		else
			ft_replace_old_texture(data, data->x - 1, data->y);
	}
	mlx_image_to_window(data->mlx, data->graph->player, data->x * 40, data->y * 40);
}

void move(void *data)
{
	int	mvmt;

	mvmt = ft_move(data);
	ft_reload_map(data, mvmt);
}

void	ft_parse_map(t_init_map *so_long)
{
	xpm_t* xpm;

	so_long->graph = malloc(sizeof(t_graph));
	xpm = mlx_load_xpm42(PLAYER);
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
}

int	spe_strlen(char *str)
{
	size_t	val;

	if (!str)
		return (0);
	val = 0;
	while (str[val] && str[val] != '\n')
		val++;
	return (val);
}

void ft_write_map(t_init_map *so_long)
{
	char		*line;
	int			fd;
	int i;
	int j;

	fd = open(so_long->fn, O_RDONLY);
	line = get_next_line(fd);
	so_long->map = malloc((so_long->length) * sizeof(char *));
	i = 0;
	while (i < so_long->length)
    	so_long->map[i++] = malloc((so_long->height) * sizeof(char));
	j = 0;
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			so_long->map[i][j] = line[i];
			i++;
		}
		j++;
		line = get_next_line(fd);
	}
	close(fd);
}

void ft_read_map(t_init_map *so_long)
{
    char		*line;
	int			fd;

	fd = open(so_long->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error.\nLine not found in file.");
		exit (EXIT_FAILURE);
	}
	so_long->length = spe_strlen(line);
	while (line)
	{
		if (spe_strlen(line) != so_long->length)
		{
			ft_printf("Error.\nMap invalid.");
			exit(EXIT_FAILURE);
		}
		so_long->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
	ft_write_map(so_long);
}

int	main(int argc, char **argv)
{
	t_init_map so_long;

	if (argc == 2)
	{
		ft_map_data(&so_long, argv[1]);
		ft_read_map(&so_long);
		so_long.mlx = mlx_init(so_long.length * 40, 
			so_long.height * 40, "So_long", false);
		ft_parse_map(&so_long);
		ft_create_map(&so_long);
		mlx_loop_hook(so_long.mlx, move, &so_long);
		mlx_loop(so_long.mlx);
		mlx_terminate(so_long.mlx);
		printf("Exiting the game.\n");
	}
}