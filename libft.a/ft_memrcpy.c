/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:32:12 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/14 14:03:22 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memrcpy(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
			return (dest);
	while (n--)
	{
			((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}