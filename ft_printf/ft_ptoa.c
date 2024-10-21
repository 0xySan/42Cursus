/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:14:27 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 13:28:49 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptoa(void *ptr)
{
	unsigned long	addr;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return ;
	}
	addr = (unsigned long)ptr;
	ft_putstr("0x");
	ft_ultoa(addr, "0123456789abcdef");
}
