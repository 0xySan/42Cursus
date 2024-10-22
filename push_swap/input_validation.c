/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:57:56 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/22 20:57:57 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && num > 2147483648))
			return (0);
		str++;
	}
	return (1);
}

static int	has_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	value;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_int(argv[i]))
			error_exit();
		value = ft_atoi(argv[i]);
		if (has_duplicates(stack, value))
			error_exit();
		push(stack, value);
		i--;
	}
}
