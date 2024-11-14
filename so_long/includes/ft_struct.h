/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:14:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 03:06:34 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

/**
 * A structure with all mlx_image_t of numbers from 0 to 9.
 * I don't think I have to put which params is which except that nm1 is nothing
 * the else is just n1 -> n9
 */
typedef struct s_count
{
	mlx_image_t	*nm1;
	mlx_image_t	*n0;
	mlx_image_t	*n1;
	mlx_image_t	*n2;
	mlx_image_t	*n3;
	mlx_image_t	*n4;
	mlx_image_t	*n5;
	mlx_image_t	*n6;
	mlx_image_t	*n7;
	mlx_image_t	*n8;
	mlx_image_t	*n9;
}	t_count;

/**
 * A structure with all mlx_image_t equivalent inside.
 * 
 * @param wall The image of the wall xpm.
 * @param empty The image of the empty xpm.
 * @param collect The image of the collect xpm.
 * @param exit The image of the exit xpm.
 * @param player The image of the player xpm.
 * @param enemy The image of the enemy xpm.
 */
typedef struct s_graph
{
	mlx_image_t	*wall;
	mlx_image_t	*empty;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*enemy;
}	t_graph;

/**
 * A structure with all of important features to init or/and move/reload the map.
 * All values are initialized with it's first point, 
 * almost all values change during the gameplay.
 * Some values can be changed, 
 * some other are better to leave at it's initialized value.
 * 
 * @param height The height of the map.
 * @param length The length of the map.
 * @param x The x position of the player.
 * @param y The y position of the player.
 * @param d_row The movement possible in a row.
 * @param d_col The movement possible in a column.
 * @param player The number of player in the map.
 * @param collectable The number of collectable in the map.
 * @param step The number of step the player has made in game, 
 * this value increment each time the player move.
 * @param exit The number of exit in the map.
 * @param map The whole map in 2 arrays of char.
 * @param visited The whole visited map to check if the map is possible or not.
 * @param mlx The struct mlx_t at initialization of the MLX42 window.
 * @param fn The result of the open(fd).
 * @param graph The t_graph struct, it is to have all mlx textures.
 * @param graph The t_count struct, it is to have all mlx textures for numbers.
 * inside of this one structure.
 * @param canexit A int value to check if the player can exit the map.
 * @param cancollect A int value to check if the player 
 * can collect all the collectables.
 * @param error_type A int value to return the error type.
 * @param animation_index The index of which animations the player is.
 * @param animations All of the xpm's path for the player's animations.
 * @param last_movement The last movement of the player as an array of int.
 * @param last_time The last time the player made a movement.
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
	t_count	*count;
	int		canexit;
	int		cancollect;
	int		error_type;
	int		animation_index;
	char	***animations;
	int		last_movement;
	int		last_time;
	int		*key_states;
	int		*numbers;
}	t_init_map;

#endif