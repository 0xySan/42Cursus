/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:44:44 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 22:45:33 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_node	*current;

	smallest = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

static void	move_to_top(t_stack *stack, int value)
{
	int		index;
	int		size;
	t_node	*current;

	index = 0;
	size = stack->size;
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			break ;
		current = current->next;
		index++;
	}
	if (index <= size / 2)
		while (index-- > 0)
			ra(stack);
	else
	{
		index = size - index;
		while (index-- > 0)
			rra(stack);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	smallest;
	int	second_smallest;

	smallest = find_smallest(a);
	move_to_top(a, smallest);
	pb(a, b);
	second_smallest = find_smallest(a);
	move_to_top(a, second_smallest);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->top->value > a->top->next->value)
		sa(a);
}
