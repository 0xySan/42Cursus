/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:39:19 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 11:32:38 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	start;
	char	c2;

	start = -1;
	c2 = c;
	while (++start < n)
		if (((char *)s)[start] == c2)
			return ((void *)&(((char *)s)[start]));
	return (0);
}
