/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:45:08 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 21:50:12 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest(t_stack *b, int number)
{
	t_node	*temp;
	int		mindiff;
	int		mindiffpos;
	int		pos;

	mindiff = MAX_INT;
	mindiffpos = 0;
	pos = 1;
	temp = b->top;
	while (pos != b->size + 1)
	{
		if (abs(number - temp->value) < mindiff && temp->value < number)
		{
			mindiff = abs(number - temp->value);
			mindiffpos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (mindiffpos);
}

void	sort_three_reverse(t_stack *b)
{
	int	top;
	int	middle;
	int	bottom;

	top = b->top->value;
	middle = b->top->next->value;
	bottom = b->top->next->next->value;
	if (top < middle && middle > bottom && top > bottom)
		sb(b);
	else if (top < middle && middle < bottom)
	{
		sb(b);
		rrb(b);
	}
	else if (top < middle && middle > bottom && top < bottom)
		rb(b);
	else if (top > middle && middle < bottom && top > bottom)
	{
		sb(b);
		rb(b);
	}
	else if (top > middle && middle < bottom && top < bottom)
		rrb(b);
}

int	is_reverse_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	search_min(t_stack *b)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		i;

	min = MAX_INT;
	min_pos = 0;
	i = 0;
	current = b->top;
	while (current)
	{
		if (current->value <= min)
		{
			min = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}
