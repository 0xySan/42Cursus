/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:51 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/07 17:02:00 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	sort_stack(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	// while (a->size > 3)
	// {
	// }
	// sort_three(a);
	// while (b->size > 0)
	// 	pa(a, b);
	turk_sort(a);
	turk_sort(b);
}
