/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:51 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 23:11:46 by etaquet          ###   ########.fr       */
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

static void	optimize_rotation(t_stack *a, t_stack *b, int *a_rot, int *b_rot)
{
	while (*a_rot > 0 && *b_rot > 0)
	{
		rr(a, b);
		(*a_rot)--;
		(*b_rot)--;
	}
	while (*a_rot < 0 && *b_rot < 0)
	{
		rrr(a, b);
		(*a_rot)++;
		(*b_rot)++;
	}
}

static void	rotate_stacks(t_stack *a, t_stack *b, int a_rot, int b_rot)
{
	optimize_rotation(a, b, &a_rot, &b_rot);
	while (a_rot > 0)
	{
		ra(a);
		a_rot--;
	}
	while (a_rot < 0)
	{
		rra(a);
		a_rot++;
	}
	while (b_rot > 0)
	{
		rb(b);
		b_rot--;
	}
	while (b_rot < 0)
	{
		rrb(b);
		b_rot++;
	}
}

void	sort_b(t_stack *a, t_stack *b)
{
	t_bcost	cost;

	find_best_move(a, b, &cost);
	rotate_stacks(a, b, cost.best_a_rot, cost.best_b_rot);
	put_pos(a, b, search_pos(b, a->top->value));
}

void	sort_stack(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	pb(a, b);
	sort_three_reverse(b);
	while (a->size > 0)
		sort_b(a, b);
	if (search_min(b) <= b->size)
		while (!is_reverse_sorted(b))
			rb(b);
	else
		while (!is_reverse_sorted(b))
			rrb(b);
	while (b->size > 0)
		pa(a, b);
}
