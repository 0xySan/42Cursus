/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:14:27 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/22 19:41:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptoa(void *ptr)
{
	unsigned long	addr;
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	len = ft_putstr("0x");
	ft_ultoa(addr, "0123456789abcdef", &len);
	return (len);
}
