/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:51 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 02:18:02 by etaquet          ###   ########.fr       */
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
	t_node	*temp;
	int	i;
	int number;
	int cost = INT_MAX;

	temp = a->top;
	i = 0;
	number = a->top->value;
	while(temp)
	{
		pos = search_pos(b, temp->value);
		if (i <= a->size/2)
		{
			if (pos <= b->size/2)
			{
				if ((i + pos + 1) < cost)
				{
					number = temp->value;
					cost = i + pos + 1;
					
				}
			}
			else
			{
				if ((i + b->size - pos + 1) < cost)
				{
					number = temp->value;
					cost = i + pos + 1;
				}
			}
		}
		else
		{
			if (pos <= b->size/2)
			{
				if ((a->size - i + b->size - pos + 1) < cost)
				{
					number = temp->value;
					cost = i + b->size - pos + 1;
				}
			}
			else
			{
				if ((i + b->size - pos + 1) < cost)
				{
					number = temp->value;
					cost = a->size - i + b->size - pos + 1;
				}
			}
		}
		temp = temp->next;
		i++;
	}
	if (cost <= a->size)
	{
		while (a->top->value != number)
			ra(a);
	}
	else
	{
		while (a->top->value != number)
			rra(a);
	}
	pos = search_pos(b, a->top->value);
	put_pos(a, b, pos);
}

void	sort_two_reverse(t_stack *a)
{
	if (a->top->value < a->top->next->value)
		sa(a);
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

static int search_min(t_stack *b)
{
	t_node *current;
	int	min;
	int	min_pos;
	int	i;

	min = INT_MAX;
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
	// turk_sort(b);
	// turk_sort(a);
}
