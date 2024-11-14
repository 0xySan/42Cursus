/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:03:41 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/14 03:19:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_fill_numbers(t_init_map *so_long)
{
	int	num;
	int	index;

	index = 0;
	num = so_long->step;
	while (num > 0 && index < so_long->length)
	{
		so_long->numbers[index++] = num % 10;
		num /= 10;
	}
}

void	ft_change_numbers(t_init_map *so_long)
{
	int	start;
	int	end;
	int	temp;

	ft_fill_numbers(so_long);
	start = 0;
	end = 0;
	while (so_long->numbers[end] != -1 && end < so_long->length)
		end++;
	end--;
	while (start < end)
	{
		temp = so_long->numbers[start];
		so_long->numbers[start++] = so_long->numbers[end];
		so_long->numbers[end--] = temp;
	}
}

void	_ft_check_number_1(t_init_map *data, int i, int height)
{
	if (data->numbers[i] == -1)
		mlx_image_to_window(data->mlx, data->count->nm1, i * 40, height * 40);
	else if (data->numbers[i] == 0)
		mlx_image_to_window(data->mlx, data->count->n0, i * 40, height * 40);
	else if (data->numbers[i] == 1)
		mlx_image_to_window(data->mlx, data->count->n1, i * 40, height * 40);
	else if (data->numbers[i] == 2)
		mlx_image_to_window(data->mlx, data->count->n2, i * 40, height * 40);
	else if (data->numbers[i] == 3)
		mlx_image_to_window(data->mlx, data->count->n3, i * 40, height * 40);
}

void	_ft_check_number_2(t_init_map *data, int i, int height)
{
	if (data->numbers[i] == 4)
		mlx_image_to_window(data->mlx, data->count->n4, i * 40, height * 40);
	else if (data->numbers[i] == 5)
		mlx_image_to_window(data->mlx, data->count->n5, i * 40, height * 40);
	else if (data->numbers[i] == 6)
		mlx_image_to_window(data->mlx, data->count->n6, i * 40, height * 40);
	else if (data->numbers[i] == 7)
		mlx_image_to_window(data->mlx, data->count->n7, i * 40, height * 40);
	else if (data->numbers[i] == 8)
		mlx_image_to_window(data->mlx, data->count->n8, i * 40, height * 40);
	else if (data->numbers[i] == 9)
		mlx_image_to_window(data->mlx, data->count->n9, i * 40, height * 40);
}

void	ft_show_numbers(t_init_map *data)
{
	int	height;
	int	i;

	height = data->height;
	i = 0;
	ft_change_numbers(data);
	while (i < data->length)
	{
		_ft_check_number_1(data, i, height);
		_ft_check_number_2(data, i, height);
		i++;
	}
}
