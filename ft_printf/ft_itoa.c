/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:01:30 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/23 15:11:58 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_iltoa(long n)
{
	if (n >= 10)
		return (ft_itoa(n / 10) + ft_itoa(n % 10));
	return (ft_putchar(n + '0'));
}

int	ft_itoa(int n)
{
	long	ln;

	ln = n;
	if (n < 0)
		return (write(1, "-", 1) + ft_iltoa(-ln));
	return (ft_iltoa(ln));
}
