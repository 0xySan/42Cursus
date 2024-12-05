/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 10:28:59 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_ft_ultoa(unsigned long nbr, const char *base)
{
	if (nbr >= 16)
		return (_ft_ultoa(nbr / 16, base) + ft_putchar(base[nbr % 16]));
	return (ft_putchar(base[nbr]));
}

int	ft_ultoa(unsigned long nbr, const char *base)
{
	return (_ft_ultoa(nbr, base));
}