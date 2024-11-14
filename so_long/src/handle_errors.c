/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:51:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 02:20:42 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_print_errors_1(t_init_map *so_long, int error_type, va_list args)
{
	if (error_type == 1)
	{
		ft_printf("Error\nThe coins or exit are not accessible from the map.");
		ft_printf("\nTry not enclosing them with '1' or 'S' characters.\n");
		ft_free_less(so_long);
		exit(1);
	}
	if (error_type == 2)
	{
		ft_printf("Error\n'%d' player(s) were found in the map try putting/",
			va_arg(args, int));
		ft_printf("removing some.\nThey are the 'E' characters on the map.\n");
		ft_free_some(so_long);
		exit(2);
	}
	if (error_type == 3)
	{
		ft_printf("Error\nNo coins were found in the map, try ");
		ft_printf("adding them by putting 'C' characters on the map.\n");
		ft_free_less(so_long);
		exit(3);
	}
}

static void	_print_errors_2(t_init_map *so_long, int error_type, va_list args)
{
	if (error_type == 4)
	{
		ft_printf("Error\n'%d' exit were found in the map ", va_arg(args, int));
		ft_printf("try putting/removing some.\n");
		ft_printf("They are the 'E' characters on the map.\n");
		ft_free_less(so_long);
		exit(4);
	}
	if (error_type == 5)
	{
		ft_printf("Error\nThe map isn't rectangle : ");
		ft_printf("length of '%d' isn't supposed to be height of '%d'.\n",
			va_arg(args, int), va_arg(args, int));
		ft_printf("Try adding a line or a character per line so that they ");
		ft_printf("aren't the same, e.g : 6 lines != 4 characters per line.\n");
		ft_free_less(so_long);
		exit(5);
	}
}

static void	_print_errors_3(t_init_map *so_long, int error_type, va_list args)
{
	if (error_type == 6)
	{
		ft_printf("Error\nWalls are not completely closed.\nTry putting only");
		ft_printf(" the characters '1' for the walls, e.g of a valid closed ");
		ft_printf("map : \n11111\n100E1\n10C01\n1P001\n11111\n");
		ft_free_less(so_long);
		exit(6);
	}
	if (error_type == 7)
	{
		ft_printf("Error\nInvalid letter in map : ['S','1','0','E','P','C']");
		ft_printf(" is usable, '%c' isn't.\n", va_arg(args, int));
		ft_free_less(so_long);
		exit(7);
	}
}

static void	_print_errors_4(t_init_map *so_long, int error_type)
{
	if (error_type == 8)
	{
		ft_printf("Error\nLength of lines in the map aren't the same.\n");
		ft_printf("Try putting the exact numbers of characters per lines.\n");
		ft_free(so_long);
		exit(8);
	}
	if (error_type == 9)
	{
		ft_printf("Error\nThe file either doesn't exist or is just empty.\n");
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
