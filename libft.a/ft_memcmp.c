/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:42:28 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/09 18:02:25 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	start;

	if (n <= 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	start = -1;
	while (++start < n - 1)
	{
		if (((char *)s1)[start] != ((char *)s2)[start])
			return (((char *)s1)[start] - ((char *)s2)[start]);
	}
	return (((char *)s1)[start] - ((char *)s2)[start]);
}