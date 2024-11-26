/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:43:19 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 21:51:27 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_pos_first_half(t_stack *a, t_stack *b, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		rb(b);
		i++;
	}
	pb(a, b);
}

static void	put_pos_second_half(t_stack *a, t_stack *b, int pos)
{
	int	i;

	i = 0;
	while (i < b->size - pos)
	{
		rrb(b);
		i++;
	}
	pb(a, b);
}

void	put_pos(t_stack *a, t_stack *b, int pos)
{
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
	else if (pos <= b->size / 2)
		put_pos_first_half(a, b, pos);
	else
		put_pos_second_half(a, b, pos);
}
