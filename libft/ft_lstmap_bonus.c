/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:57:12 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 10:57:42 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;
	t_list	**temp;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	current = lst;
	while (current)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temp = &new_list;
		while (*temp)
			temp = &(*temp)->next;
		*temp = new_node;
		current = current->next;
	}
	return (new_list);
}
