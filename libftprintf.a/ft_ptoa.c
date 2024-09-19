/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:14:27 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/19 23:04:11 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_ptoa(void *ptr)
{
    unsigned long addr;

    if(!ptr)
    {
        write(1,"(nil)", 5);
        return ;
    }

    addr = (unsigned long)ptr;
    ft_putstr("0x");
    ft_ultoa(addr, "0123456789abcdef");
}