/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:51 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/25 22:30:27 by etaquet          ###   ########.fr       */
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

static int	check_if_highest(t_stack *b, int number)
{
	t_node	*temp;
	int		pos;

	pos = 1;
	temp = b->top;
	while (pos != b->size + 1)
	{
		if (number < temp->value)
			return (0);
		temp = temp->next;
		pos++;
	}
	return (1);
}

static int	check_if_lowest(t_stack *b, int number)
{
	t_node	*temp;
	int		pos;

	pos = 1;
	temp = b->top;
	while (pos != b->size + 1)
	{
		if (number > temp->value)
			return (0);
		temp = temp->next;
		pos++;
	}
	return (1);
}

static int	find_lowest(t_stack *b, int number)
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
		if (abs(number - temp->value) < mindiff && temp->value < number)
		{
			mindiff = abs(number - temp->value);
			mindiffpos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return mindiffpos;
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
	if (check_if_highest(b, number))
	{
		while (pos != b->size + 1)
		{
			if (abs(number - temp->value) < mindiff)
			{
				mindiff = abs(number - temp->value);
				mindiffpos = pos - 1;
			}
			temp = temp->next;
			pos++;
		}
	}
	else if (check_if_lowest(b, number))
	{
		while (pos != b->size + 1)
		{
			if (abs(number - temp->value) < mindiff)
			{
				mindiff = abs(number - temp->value);
				mindiffpos = pos;
			}
			temp = temp->next;
			pos++;
		}
	}
	else
		return find_lowest(b, number) - 1;
	return mindiffpos;
}

static void	put_pos(t_stack *a, t_stack *b, int pos)
{
	int	i;

	i = 0;
	if (pos == 0)
		pb(a, b);
	else if (pos == 1)
	{
		pb(a, b);
		sb(b);
	}
	else if (pos == b->size)
	{
		pb(a, b);
		rb(b);
	}
	else
	{
		if (pos <= b->size/2)
		{
			while (i < pos)
			{
				rb(b);
				i++;
			}
			pb(a, b);
		}
		else
		{
			while (i < b->size - pos)
			{
				rrb(b);
				i++;
			}
			pb(a, b);
		}
	}
}

static void	sort_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	number;

	number = a->top->value;
	pos = search_pos(b, number);
	put_pos(a, b, pos);
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
		sb(a);
	else if (top < middle && middle < bottom)
	{
		sb(a);
		rrb(a);
	}
	else if (top < middle && middle > bottom && top < bottom)
		rb(a);
	else if (top > middle && middle < bottom && top > bottom)
	{
		sb(a);
		rb(a);
	}
	else if (top > middle && middle < bottom && top < bottom)
		rrb(a);
}

int is_reverse_sorted(t_stack *stack)
{
    t_node *current;

    current = stack->top;
    while (current && current->next)
    {
        if (current->value < current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	pb(a, b);
	sort_three_reverse(b);
	while (a->size > 0)
		sort_b(a, b);
	while (!is_reverse_sorted(b))
		rb(b);
	while (b->size > 0)
		pa(a, b);
	turk_sort(a);
}
