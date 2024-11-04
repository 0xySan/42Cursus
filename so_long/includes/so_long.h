/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:34:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/04 03:09:18 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./textures/wall.xpm42"
# define EMPTY "./textures/empty.xpm42"
# define UP1 "./textures/UP1.xpm42"
# define UP2 "./textures/UP2.xpm42"
# define UP3 "./textures/UP3.xpm42"
# define UP4 "./textures/UP4.xpm42"
# define DP1 "./textures/DP1.xpm42"
# define DP2 "./textures/DP2.xpm42"
# define DP3 "./textures/DP3.xpm42"
# define DP4 "./textures/DP4.xpm42"
# define RP1 "./textures/RP1.xpm42"
# define RP2 "./textures/RP2.xpm42"
# define RP3 "./textures/RP3.xpm42"
# define RP4 "./textures/RP4.xpm42"
# define LP1 "./textures/LP1.xpm42"
# define LP2 "./textures/LP2.xpm42"
# define LP3 "./textures/LP3.xpm42"
# define LP4 "./textures/LP4.xpm42"
# define ENEMY "./textures/enemy.xpm42"
# define EXIT "./textures/exit.xpm42"
# define COLLECT "./textures/collectible.xpm42"
// # define WIN "./xpm_textures/winner.xpm42"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx/mlx42.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

/**
 * A structure with all mlx_image_t equivalent inside.
 * 
 * @param wall The image of the wall xpm.
 * @param empty The image of the empty xpm.
 * @param collect The image of the collect xpm.
 * @param exit The image of the exit xpm.
 * @param player The image of the player xpm.
 * @param winner The image of the winner xpm.
 * @param enemy The image of the enemy xpm.
 */
typedef struct s_graph
{
	mlx_image_t	*wall;
	mlx_image_t	*empty;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*winner;
	mlx_image_t	*enemy;
}	t_graph;

/**
 * A structure with all of important features to init or/and move/reload the map.
 * All values are initialized with it's first point, almost all values change during the gameplay.
 * Some values can be changed, some other are better to leave at it's initialized value.
 * 
 * @param height The height of the map.
 * @param length The length of the map.
 * @param x The x position of the player.
 * @param y The y position of the player.
 * @param d_row The movement possible in a row.
 * @param d_col The movement possible in a column.
 * @param player The number of player in the map.
 * @param collectable The number of collectable in the map.
 * @param step The number of step the player has made in game, this value increment each time the player move.
 * @param exit The number of exit in the map.
 * @param map The whole map in 2 arrays of char.
 * @param visited The whole visited map to check if the map is possible or not.
 * @param mlx The struct mlx_t at initialization of the MLX42 window.
 * @param fn The result of the open(fd).
 * @param graph The t_graph struct, it is to have all mlx textures inside of this one structure.
 * @param canexit A int value to check if the player can exit the map.
 * @param cancollect A int value to check if the player can collect all the collectables.
 * @param error_type A int value to return the error type.
 * @param animation_index The index of which animations the player is.
 * @param animations All of the xpm's path for the player's animations.
 * @param last_movement The last movement of the player as an array of int.
 * @param key_states An array of int to prevent fast movement.
 */
typedef struct s_init_map
{
	int		height;
	int		length;
	int		x;
	int		y;
	int		*d_row;
	int		*d_col;
	int		player;
	int		collectable;
	int		step;
	int		exit;
	char	**map;
	int		**visited;
	void	*mlx;
	char	*fn;
	t_graph	*graph;
	int		canexit;
	int		cancollect;
	int		error_type;
	int		animation_index;
	char	***animations;
	int		last_movement;
	int		*key_states;
}	t_init_map;

/**
 * Checks if the map is doable or not.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 * @returns 0 if there is no error, a expected number if one is there.
 */
int		ft_map_checker(t_init_map *data);

/**
 * Replaces the texture of the previous space the player was.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 * @param[in] x The x value of the previous space.
 * @param[in] y The y value of the previous space.
 */
void	ft_replace_old_texture(t_init_map *data, int x, int y);

/**
 * Reload the map and moves the player if needed.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 * @param[in] mvmt The movement the player has done.
 */
void	ft_reload_map(t_init_map *data, int mvmt);

/**
 * Free some of the data to have no leaks.
 * This function is needed because in some case not everything is allocated.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_free_some(t_init_map *so_long);

/**
 *  Initialize all the graph's xpm value.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_parse_map(t_init_map *so_long);

/**
 *  Create the map and places the textures to be able to see the graphics.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_create_map(t_init_map *data);

/**
 *  Create an image at the x:i and y:j place.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 * @param[in] i The x value where the image will be placed.
 * @param[in] j The y value where the image will be placed.
 */
void	ft_create_img(t_init_map *data, int i, int j);

/**
 *  A function to reload everything because it is the parent that calls the children func.
 * 
 * @param[in] data The t_init_map struct as a void pointer because mlx_loop_hook gives a void pointer.
 */
void	ft_reload_mvmt(void *data);

/**
 *  Free all of the data to have no leaks.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_free_all(t_init_map *so_long);

/**
 *  Initialize all the values of the t_init_map struct.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_map_data(t_init_map *so_long, char *name);

/**
 *  Read all the map and write all of it's value in the so_long.map.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_read_map(t_init_map *so_long);

/**
 *  Move the player one space and call another func.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 */
int		ft_move(t_init_map *data);

/**
 *  Check the count of the player, exit and collectable in the map.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 */
int		ft_check_count(t_init_map *data);

/**
 * Free less data to have no leaks.
 * This function is needed because if nothing is allocated I still need to free the default values.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_free_less(t_init_map *so_long);

#endif