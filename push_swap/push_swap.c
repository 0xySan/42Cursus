/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:56:18 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/10 03:44:11 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

int	count_numbers(char **argv)
{
	int	index;

	index = 0;
	while (argv[index])
		index++;
	return (index);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**numbers;

	init_stacks(&a, &b);
	if (argc < 2)
		return (free_stack(&a), free_stack(&b), printf("Error\n"), 0);
	else if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		argc = count_numbers(numbers);
	}
	else
		numbers = argv;
	if (!numbers[1])
		return (free_stack(&a), free_stack(&b), printf("Error\n"), 0);
	init_stack(&a, argc, numbers);
	if (!is_sorted(&a))
		sort_small(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
