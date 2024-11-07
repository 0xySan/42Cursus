/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:00:36 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/07 20:43:25 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push(a, pop(b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push(b, pop(a));
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}