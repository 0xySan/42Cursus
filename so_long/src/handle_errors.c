/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:51:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/20 13:33:48 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_print_errors_1(t_init_map *so_long, int error_type, va_list args)
{
	if (error_type == 1)
	{
		ft_dprintf(2, "%s",
			"Error\nThe coins or exit are not accessible from the map.");
		ft_dprintf(2, "\nTry not enclosing them with '1' or 'S' characters.\n");
		ft_free_less(so_long);
		exit(1);
	}
	if (error_type == 2)
	{
		ft_dprintf(2, "Error\n'%d' player(s) were found in the map try putting",
			va_arg(args, int));
		ft_dprintf(2, "%s",
			"/removing some.\nThey are the 'P' characters on the map.\n");
		ft_free_less(so_long);
		exit(2);
	}
	if (error_type == 3)
	{
		ft_dprintf(2, "Error\nNo coins were found in the map, try ");
		ft_dprintf(2, "adding them by putting 'C' characters on the map.\n");
		ft_free_less(so_long);
		exit(3);
	}
}

static void	_print_errors_2(t_init_map *so_long, int error_type, va_list args)
{
	if (error_type == 4)
	{
		ft_dprintf(2, "Error\n'%d' exit were found in the ", va_arg(args, int));
		ft_dprintf(2, "map try putting/removing some.\n");
		ft_dprintf(2, "They are the 'E' characters on the map.\n");
		ft_free_less(so_long);
		exit(4);
	}
	if (error_type == 5)
	{
		ft_dprintf(2, "Error\nThe map isn't rectangle : length of");
		ft_dprintf(2, " '%d' isn't supposed to be height of '%d'.\nTry adding",
			va_arg(args, int), va_arg(args, int));
		ft_dprintf(2, " a line or a character per line so that they aren't");
		ft_dprintf(2, " the same, e.g : 6 lines != 4 characters per line.\n");
		ft_free_less(so_long);
		exit(5);
	}
}

static void	_print_errors_3(t_init_map *so_long, int error_type, va_list args)
{
	if (error_type == 6)
	{
		ft_dprintf(2, "Error\nWalls are not completely closed.\nTry putting ");
		ft_dprintf(2, " the characters '1' for the walls, e.g of a valid only");
		ft_dprintf(2, "closed map : \n11111\n100E1\n10C01\n1P001\n11111\n");
		ft_free_less(so_long);
		exit(6);
	}
	if (error_type == 7)
	{
		ft_dprintf(2, "%s",
			"Error\nInvalid letter in map : ['S','1','0','E','P','C']");
		ft_dprintf(2, " is usable, '%c' isn't.\n", va_arg(args, int));
		ft_free_less(so_long);
		exit(7);
	}
}

static void	_print_errors_4(t_init_map *so_long, int error_type)
{
	if (error_type == 8)
	{
		ft_dprintf(2, "Error\nLength of lines in the map aren't the same.\n");
		ft_dprintf(2, "%s",
			"Try putting the exact numbers of characters per lines.\n");
		ft_free(so_long);
		exit(8);
	}
	if (error_type == 9)
	{
		ft_dprintf(2, "%s",
			"Error\nThe file either doesn't exist or is just empty.\n");
		ft_free(so_long);
		exit(9);
	}
}

void	ft_handle_errors(t_init_map *so_long, int error_type, ...)
{
	va_list	args;

	va_start(args, error_type);
	_print_errors_1(so_long, error_type, args);
	_print_errors_2(so_long, error_type, args);
	_print_errors_3(so_long, error_type, args);
	_print_errors_4(so_long, error_type);
	va_end(args);
}
