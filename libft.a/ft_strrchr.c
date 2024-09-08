/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:16:33 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/08 13:21:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	start;

	if (!s)
		return (0);
    start = ft_strlen(s);
	while (s[--start])
	{
		if (s[start] == c)
			return ((char*)&s[start]);
	}
	return (0);
}
