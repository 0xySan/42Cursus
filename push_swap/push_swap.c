/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:56:18 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/21 03:46:58 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

void	free_numbers(char **numbers)
{
	int	index;

	index = 0;
	while (numbers[++index])
		free(numbers[index]);
	free(numbers);
}

int	count_numbers(char **argv)
{
	int	index;

	index = 0;
	while (argv[index])
		index++;
	return (index);
}

int	init_val(t_value *val, int argc, char **argv)
{
	if (argc < 2)
		return (write(1, "Error\n", 6), 1);
	else if (argc == 2)
	{
		val->numbers = ft_split(argv[1], ' ');
		val->n = count_numbers(val->numbers);
	}
	else
	{
		val->numbers = argv;
		val->n = argc;
	}
	if (!val->numbers[1])
		return (free_numbers(val->numbers), write(1, "Error\n", 6), 1);
	val->argc = argc;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_value	val;

	init_stacks(&a, &b);
	if (init_val(&val, argc, argv))
	{
		if (argc == 2)
			return (free_numbers(val.numbers), write(1, "Error\n", 6), 1);
		else
			return (write(1, "Error\n", 6), 1);
	}
	init_stack(&a, &b, val);
	if (!is_sorted(&a))
		sort_small(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (argc == 2)
		free_numbers(val.numbers);
	return (0);
}
