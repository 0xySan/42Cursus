/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:17:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 03:22:03 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_graph(t_init_map *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			j++;
		free(so_long->animations[i]);
		i++;
	}
	free(so_long->animations);
}

void	ft_free(t_init_map *so_long)
{
	free(so_long->d_col);
	free(so_long->d_row);
	free(so_long->key_states);
	ft_free_graph(so_long);
}

void	ft_free_less(t_init_map *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->length)
	{
		j = 0;
		while (j < so_long->height)
			j++;
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	ft_free(so_long);
}

void	ft_free_some(t_init_map *so_long)
{
	int	i;
	int	j;

	ft_free_less(so_long);
	i = 0;
	while (i < so_long->length)
	{
		j = 0;
		while (j < so_long->height)
			j++;
		free(so_long->visited[i]);
		i++;
	}
	free(so_long->numbers);
	free(so_long->visited);
}

void	ft_free_all(t_init_map *so_long)
{
	ft_free_some(so_long);
	free(so_long->graph);
}
