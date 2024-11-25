/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:01:30 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/20 13:18:33 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_iltoa(long n, int fd)
{
	if (n >= 10)
		return (ft_itoa(n / 10, fd) + ft_itoa(n % 10, fd));
	return (ft_putchar_fd(n + '0', fd));
}

int	ft_itoa(int n, int fd)
{
	long	ln;

	ln = n;
	if (n < 0)
		return (write(fd, "-", 1) + ft_iltoa(-ln, fd));
	return (ft_iltoa(ln, fd));
}
