/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:34:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/20 13:34:39 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx/mlx42.h"
# include "../gnl/get_next_line.h"
# include "../ft_dprintf/ft_printf.h"
# include "./ft_struct.h"
# include "./ft_defines.h"

/**
 * Checks if the map is doable or not.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 * @returns 0 if there is no error, a expected number if one is there.
 */
void	ft_map_checker(t_init_map *data);

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
 *  A function to reload everything because
 * it is the parent that calls the children func.
 * 
 * @param[in] data The t_init_map struct as a void pointer 
 * because loop_hook gives a void pointer.
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
void	ft_check_count(t_init_map *data);

/**
 * Free less data to have no leaks.
 * This function is needed because if nothing 
 * is allocated I still need to free the default values.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_free_less(t_init_map *so_long);

/**
 *  Move the player one space and call another func.
 * 
 * @param[in] data The t_init_map struct as a pointer to be able to modify it.
 * @param[in] mvmt The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_do_mvmt(t_init_map *data, int mvmt);

/**
 * Free less data to have no leaks.
 * This function is needed because if there is really NOTHING 
 * allocated and I still need to free the default values.
 * 
 * @param[in] so_long The t_init_map struct as a pointer to be able to modify it.
 */
void	ft_free(t_init_map *so_long);

void	ft_parse_numbers(t_init_map *so_long);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_handle_errors(t_init_map *so_long, int error_type, ...);

int		spe_strlen(char *str);

void	ft_show_numbers(t_init_map *data);

void	ft_malloc_numbers(t_init_map *so_long);

#endif