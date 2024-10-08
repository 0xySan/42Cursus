/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:09:25 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/12 18:30:57 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*r_value;
	int		start;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	r_value = malloc(sizeof(char) * (ft_count_nb(n) + 1));
	if (!r_value)
		return (NULL);
	start = 0;
	if (n < 0)
	{
		n = -n;
		r_value[start++] = '-';
	}
	while (n)
	{
		r_value[start++] = (n % 10) + '0';
		n = n / 10;
	}
	r_value[start] = '\0';
	ft_strrev(r_value);
	return (r_value);
}