/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:09:25 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/15 17:16:13 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_strrev(char *str)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

static int	ft_count_nb(int nb)
{
	int	value;

	value = 0;
	while (nb > 9)
	{
		nb /= 10;
		value++;
	}
	return (value);
}

static void	ft_calc_itoa(int n, char *r_value)
{
	int	start;

	start = 0;
	while (n)
	{
		r_value[start++] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*r_value;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		r_value = malloc(sizeof(char) * (ft_count_nb(n) + 2));
		if (!r_value)
			return (NULL);
		r_value[ft_count_nb(n) + 1] = '-';
		r_value[ft_count_nb(n) + 2] = '\0';
	}
	else
	{
		r_value = malloc(sizeof(char) * (ft_count_nb(n) + 1));
		if (!r_value)
			return (NULL);
		r_value[ft_count_nb(n) + 1] = '\0';
	}
	ft_calc_itoa(n, r_value);
	ft_strrev(r_value);
	return (r_value);
}
