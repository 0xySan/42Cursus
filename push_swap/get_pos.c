/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:55:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/26 21:56:21 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_highest_pos(t_stack *b, int number)
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
		if (abs(number - temp->value) < mindiff)
		{
			mindiff = abs(number - temp->value);
			mindiffpos = pos - 1;
		}
		temp = temp->next;
		pos++;
	}
	return (mindiffpos);
}

int	search_lowest_pos(t_stack *b, int number)
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
		if (abs(number - temp->value) < mindiff)
		{
			mindiff = abs(number - temp->value);
			mindiffpos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (mindiffpos);
}

int	search_pos(t_stack *b, int number)
{
	if (check_if_highest(b, number))
		return (search_highest_pos(b, number));
	else if (check_if_lowest(b, number))
		return (search_lowest_pos(b, number));
	else
		return (find_lowest(b, number) - 1);
}
