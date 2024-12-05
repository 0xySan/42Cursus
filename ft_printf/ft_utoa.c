/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:42:29 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 10:30:27 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_ft_utoa(unsigned int n)
{
	if (n >= 10)
		return (_ft_utoa(n / 10) + _ft_utoa(n % 10));
	return (ft_putchar(n + '0'));
}

int	ft_utoa(unsigned int n)
{
	return (_ft_utoa(n));
}
