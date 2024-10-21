/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:16:33 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 11:31:49 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;
	char	c2;

	last_occurrence = NULL;
	c2 = c;
	while (*s)
	{
		if (*s == c2)
			last_occurrence = (char *)s;
		s++;
	}
	if (c2 == '\0')
		return ((char *)s);
	return (last_occurrence);
}
