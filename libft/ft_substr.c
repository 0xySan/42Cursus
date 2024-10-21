/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:34:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 10:58:10 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r_value;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	s_len -= start;
	if (s_len < len)
		len = s_len;
	r_value = malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	r_value = ft_memcpy(r_value, s + start, len);
	r_value[len] = '\0';
	return (r_value);
}
