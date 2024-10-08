/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:43:55 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/21 02:06:52 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	start;

	start = -1;
	while (dest && dest[++start]);
	if (start >= size)
		return (size + ft_strlen(src));
	ft_strncpy(&dest[start], src, size - start - 1);
	return (start + ft_strlen(src));
}
