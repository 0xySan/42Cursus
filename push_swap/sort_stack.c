/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:51 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/21 03:52:04 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>

static void	turk_sort(t_stack *a)
{
	t_node	*temp;

	temp = a->top;
	while (temp->next)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("%d\n", temp->value);
}

static int	search_pos(t_stack *b, int number)
{
	t_node	*temp;
	int		mindiff;
	int		mindiffpos;
	int		pos;

	mindiff = INT_MAX;
	mindiffpos = 0;
	pos = 1;
	temp = b->top;
	while (pos != b->size + 1)
	{
		if (abs(number - temp->value <= mindiff) && temp->value >= number)
		{
			mindiff = abs(number - temp->value);
			mindiffpos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return mindiffpos;
}

static void	put_pos(t_stack *b, int pos)
{
	int	i;

	i = 0;
	if (pos == 0)
		return ;
	else if (pos == 1)
		sb(b);
	else if (pos == b->size)
		rb(b);
	else
	{
		while (i < pos)
		{
			sb(b);
			rb(b);
			i++;
		}
		while (i > 0)
		{
			rrb(b);
			i--;
		}
	}
}

static void	sort_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	number;

	number = a->top->value;
	pos = search_pos(b, number);
	pb(a, b);
	put_pos(b, pos);
}

void	sort_two_reverse(t_stack *a)
{
	if (a->top->value < a->top->next->value)
		sa(a);
}

void	sort_three_reverse(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top < middle && middle > bottom && top > bottom)
		sa(a);
	else if (top < middle && middle < bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top < middle && middle > bottom && top < bottom)
		ra(a);
	else if (top > middle && middle < bottom && top > bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top > middle && middle < bottom && top < bottom)
		rra(a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	pb(a, b);
	sort_three_reverse(b);
	while (a->size > 0)
		sort_b(a, b);
	while (b->size > 0)
		pa(a, b);
	turk_sort(a);
}
