/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:31:03 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 03:06:45 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_ft_parse_numbers_1(t_init_map *so_long, xpm_t *xpm)
{
	xpm = mlx_load_xpm42(N4);
	if (!xpm)
		return ;
	so_long->count->n4 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N0);
	if (!xpm)
		return ;
	so_long->count->n0 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N1);
	if (!xpm)
		return ;
	so_long->count->n1 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N2);
	if (!xpm)
		return ;
	so_long->count->n2 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N3);
	if (!xpm)
		return ;
	so_long->count->n3 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
}

static void	_ft_parse_numbers_2(t_init_map *so_long, xpm_t *xpm)
{
	xpm = mlx_load_xpm42(N5);
	if (!xpm)
		return ;
	so_long->count->n5 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N6);
	if (!xpm)
		return ;
	so_long->count->n6 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N7);
	if (!xpm)
		return ;
	so_long->count->n7 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N8);
	if (!xpm)
		return ;
	so_long->count->n8 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	xpm = mlx_load_xpm42(N9);
	if (!xpm)
		return ;
	so_long->count->n9 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
}

void	ft_parse_numbers(t_init_map *so_long)
{
	xpm_t	*xpm;

	so_long->count = malloc(sizeof(t_count));
	xpm = mlx_load_xpm42(NM1);
	if (!xpm)
		return ;
	so_long->count->nm1 = mlx_texture_to_image(so_long->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	_ft_parse_numbers_1(so_long, xpm);
	_ft_parse_numbers_2(so_long, xpm);
}