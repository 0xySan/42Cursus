/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:14:40 by oxysan            #+#    #+#             */
/*   Updated: 2024/09/09 18:06:45 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int calc_len(int size, char **strs, char *sep)
{
	int	len;
	int	start;
	int	ls;

	start = 0;
	len = 0;
	ls = ft_strlen(sep);
	while (start < size)
		len += ft_strlen(strs[start++]);
	len += (ls * (size - 1));
	if (len < 1)
		len = 0;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		start;

	start = -1;
	result = malloc(sizeof(char) * (calc_len(size, strs, sep) + 1));
	result[0] = '\0';
	if (size <= 0)
		return (result);
	start = -1;
	while (++start < size)
	{
		ft_strcat(result, strs[start]);
		if (start < size - 1)
			ft_strcat(result, sep);
	}
	return (result);
}