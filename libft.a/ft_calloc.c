/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:45:50 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/14 11:11:48 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r_value;

	r_value = NULL;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ft_bzero(r_value, size);
	return (r_value);
}
