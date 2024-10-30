/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:34:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 14:10:09 by etaquet          ###   ########.fr       */
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

int	ft_map_checker(t_init_map *data);

#endif