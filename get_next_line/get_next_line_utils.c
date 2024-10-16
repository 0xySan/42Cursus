/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:43:11 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/19 14:16:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	start;

	start = 0;
	while (start < n)
		((char *) s)[start++] = c;
	return (s);
}

int	ft_strlen(const char *str)
{
	size_t	val;

	val = 0;
	while (str[val])
		val++;
	return (val);
}

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

char	*ft_substr(char const *s, unsigned int start, long len)
{
	char			*r_value;
	unsigned int	v;

	r_value = malloc(sizeof(char) * (len + 1));
	if (r_value == NULL)
		return (NULL);
	v = 0;
	while (v < len && s[v + start])
	{
		r_value[v] = s[v + start];
		v++;
	}
	r_value[v] = '\0';
	return (r_value);
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
