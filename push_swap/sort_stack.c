/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:51 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/22 20:58:59 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	min = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

static void	move_min_to_top(t_stack *a)
{
	int	min;

	min = get_min(a);
	while (a->top->value != min)
	{
		if (a->top->next->value == min)
			sa(a);
		else if (a->size / 2 > 2 && a->top->next->next->value == min)
		{
			ra(a);
			sa(a);
		}
		else
			ra(a);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
