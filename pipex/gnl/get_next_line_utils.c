/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:43:11 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 12:08:17 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		start;

	if (!src)
		return (0);
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	start = -1;
	while (src[++start])
		dest[start] = src[start];
	dest[start] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	start;

	if (!s)
		return (0);
	start = -1;
	while (s[++start])
	{
		if (s[start] == c)
			return ((char *)&s[start]);
	}
	return (0);
}

void	malloc_gnl(char **leftover, char **buffer, int i)
{
	if (i == 1)
	{
		if (!*leftover)
		{
			*leftover = malloc(1);
			if (!*leftover)
				return ;
			*leftover[0] = '\0';
		}
	}
	if (i == 2)
	{
		free(*leftover);
		free(*buffer);
		*leftover = NULL;
		return ;
	}
}
