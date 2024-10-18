/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:34:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/18 13:30:33 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r_value;
	size_t	i;
	size_t	s_len;

	r_value = malloc(len + 1);
	if (!s || !r_value)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while ((i + start) < s_len && i < len)
	{
		r_value[i] = s[i + start];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
