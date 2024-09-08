/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 04:28:20 by oxy               #+#    #+#             */
/*   Updated: 2024/09/08 13:08:17 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	start;

	if (n <= 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	start = -1;
	while (++start < n - 1 && s1[start])
	{
		if (s1[start] != s2[start])
			return (s1[start] - s2[start]);
	}
	return (s1[start] - s2[start]);
}