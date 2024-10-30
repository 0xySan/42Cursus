/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:34:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 15:41:55 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./xpm_textures/wall.xpm42"
# define EMPTY "./xpm_textures/empty.xpm42"
# define PLAYER "./xpm_textures/player.xpm42"
# define EXIT "./xpm_textures/exit.xpm42"
# define COLLECT "./xpm_textures/collectible.xpm42"
// # define WIN "./xpm_textures/winner.xpm42"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx/mlx42.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_graph
{
	mlx_image_t	*wall;
	mlx_image_t	*empty;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*winner;
}	t_graph;

typedef struct s_init_map
{
	int		height;
	int		length;
	int		x;
	int		y;
	int		*d_row;
	int		*d_col;
	int		player;
	int		escape;
	int		collectable;
	int		step;
	char	**map;
	bool	**visited;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*fn;
	t_graph	*graph;

}	t_init_map;

int		ft_map_checker(t_init_map *data);
void	ft_replace_old_texture(t_init_map *data, int x, int y);
void	ft_reload_map(t_init_map *data, int mvmt);
void	ft_free_some(t_init_map *so_long);
void	ft_parse_map(t_init_map *so_long);
void	ft_create_map(t_init_map *data);
void	ft_create_img(t_init_map *data, int i, int j);
void	ft_reload_mvmt(void *data);
void	ft_free_all(t_init_map *so_long);
void	ft_map_data(t_init_map *so_long, char *name);
void	ft_read_map(t_init_map *so_long);
int		ft_move(t_init_map *data);

#endif