/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:14:27 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/18 19:17:47 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putpointer(void *ptr)
{
    unsigned long addr;

    addr = (unsigned long)ptr;
    ft_putstr("0x");
    ft_putul_base(addr, "0123456789abcdef");
}