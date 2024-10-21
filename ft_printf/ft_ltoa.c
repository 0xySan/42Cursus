/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:25:36 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 13:28:47 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ltoa(long nbr, const char *base)
{
	long	base_len;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		ft_ltoa(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
}
