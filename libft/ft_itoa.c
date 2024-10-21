/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:09:25 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 15:43:20 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_nb(long long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_rec_nbr(long n, char *r_value, int *start)
{
	if (n > 9)
	{
		ft_rec_nbr(n / 10, r_value, start);
		ft_rec_nbr(n % 10, r_value, start);
	}
	else
		r_value[(*start)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*r_value;
	int		start;
	long	nbr;

	nbr = n;
	r_value = malloc(sizeof(char) * (ft_count_nb(nbr) + 1));
	if (!r_value)
		return (NULL);
	start = 0;
	if (nbr < 0)
	{
		r_value[start++] = '-';
		nbr *= -1;
	}
	ft_rec_nbr(nbr, r_value, &start);
	r_value[start] = '\0';
	return (r_value);
}
