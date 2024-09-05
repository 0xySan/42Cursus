/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:33:33 by oxysan            #+#    #+#             */
/*   Updated: 2024/09/05 17:42:05 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	find_index(char *str, char *to_find)
{
	int	len;
	int	start;

	start = -1;
	if (!str || !to_find)
		return (0);
	len = 0;
	while (str[len])
		len++;
	if (len == 0)
		return (0);
	while (str[++start])
	{
		if (ft_strchr(str[start], to_find))
			return (start);
	}
	return (start);
}

int	len_seperated(char *str, char *to_find)
{
	int	len;
	int	start;
	int	var;

	start = 0;
	len = 0;
	while (str[start])
	{
		var = find_index(str + start, to_find);
		if (var)
		{
			len++;
			start += var;
		}
		else
			start++;
	}
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	start;

	start = 0;
	while (src && src[start] && start < n)
	{
		dest[start] = src[start];
		++start;
	}
	while (start < n)
	{
		dest[start] = '\0';
		start++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**r_value;
	int		len;
	int		start;
	int		var;

	start = 0;
	len = len_seperated(str, charset);
	r_value = malloc(sizeof(char *) * (len + 1));
	r_value[len] = 0;
	len = 0;
	while (str[start])
	{
		var = find_index(str + start, charset);
		if (var)
		{
			r_value[len] = malloc(sizeof(char) * (var + 1));
			ft_strncpy(r_value[len++], str + start, var);
			start += var;
		}
		else
			start++;
	}
	return (r_value);
}
