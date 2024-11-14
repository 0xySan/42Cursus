/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:25:01 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 04:11:49 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_malloc_some(t_init_map *so_long)
{
	so_long->d_col = malloc(sizeof(int) * 4);
	so_long->d_col[0] = -1;
	so_long->d_col[1] = 1;
	so_long->d_col[2] = 0;
	so_long->d_col[3] = 0;
	so_long->d_row = malloc(sizeof(int) * 4);
	so_long->d_row[0] = 0;
	so_long->d_row[1] = 0;
	so_long->d_row[2] = -1;
	so_long->d_row[3] = 1;
}

void	ft_malloc_numbers(t_init_map *so_long)
{
	int	i;

	i = 1;
	so_long->numbers = malloc(sizeof(int) * so_long->length);
	so_long->numbers[0] = 0;
	while (i < so_long->length)
		so_long->numbers[i++] = -1;
}

void	ft_map_data_animations(t_init_map *so_long)
{
	so_long->animations = malloc(sizeof(char **) * 4);
	so_long->animations[0] = malloc(sizeof(char *) * 4);
	so_long->animations[0][0] = UP1;
	so_long->animations[0][1] = UP2;
	so_long->animations[0][2] = UP3;
	so_long->animations[0][3] = UP4;
	so_long->animations[1] = malloc(sizeof(char *) * 4);
	so_long->animations[1][0] = DP1;
	so_long->animations[1][1] = DP2;
	so_long->animations[1][2] = DP3;
	so_long->animations[1][3] = DP4;
	so_long->animations[2] = malloc(sizeof(char *) * 4);
	so_long->animations[2][0] = LP1;
	so_long->animations[2][1] = LP2;
	so_long->animations[2][2] = LP3;
	so_long->animations[2][3] = LP4;
	so_long->animations[3] = malloc(sizeof(char *) * 4);
	so_long->animations[3][0] = RP1;
	so_long->animations[3][1] = RP2;
	so_long->animations[3][2] = RP3;
	so_long->animations[3][3] = RP4;
	so_long->last_movement = 0;
}

void	ft_map_data(t_init_map *so_long, char *name)
{
	so_long->height = 0;
	so_long->length = 0;
	so_long->collectable = 0;
	so_long->last_movement = 0;
	so_long->step = 0;
	so_long->x = 0;
	so_long->y = 0;
	so_long->player = 0;
	so_long->exit = 0;
	so_long->animation_index = 0;
	so_long->error_type = 0;
	so_long->canexit = 0;
	so_long->cancollect = 1;
	so_long->fn = name;
	so_long->last_time = 0;
	so_long->numbr_time = 0.0;
	ft_malloc_some(so_long);
	ft_map_data_animations(so_long);
}
