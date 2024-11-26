/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:50:24 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 21:51:20 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_highest(t_stack *b, int number)
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

int	check_if_lowest(t_stack *b, int number)
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

void	calculate_costs(t_stack *a, t_stack *b, int i, t_bcost *cost)
{
	if (i <= a->size / 2)
		cost->a_cost = i;
	else
		cost->a_cost = a->size - i;
	if (cost->pos <= b->size / 2)
		cost->b_cost = cost->pos;
	else
		cost->b_cost = b->size - cost->pos;
}

void	update_best_move(t_bcost *cost, int i, t_stack *a, t_stack *b)
{
	cost->best_cost = cost->current_cost;
	if (i <= a->size / 2)
		cost->best_a_rot = i;
	else
		cost->best_a_rot = -(a->size - i);
	if (cost->pos <= b->size / 2)
		cost->best_b_rot = cost->pos;
	else
		cost->best_b_rot = -(b->size - cost->pos);
}

void	find_best_move(t_stack *a, t_stack *b, t_bcost *cost)
{
	t_node	*temp;
	int		i;

	temp = a->top;
	i = 0;
	cost->best_cost = MAX_INT;
	while (temp)
	{
		cost->pos = search_pos(b, temp->value);
		calculate_costs(a, b, i, cost);
		cost->current_cost = cost->a_cost + cost->b_cost;
		if (cost->current_cost < cost->best_cost)
			update_best_move(cost, i, a, b);
		temp = temp->next;
		i++;
	}
}
