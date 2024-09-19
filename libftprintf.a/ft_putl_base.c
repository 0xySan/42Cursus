/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putl_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:25:36 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/18 19:27:57 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putl_base(long nbr, const char *base)
{
    long   base_len;

    if(nbr < 0)
    {
        write(1,"-",1);
        nbr = -nbr;
    }

    base_len = 0;
    while (base[base_len])
        base_len++;
    if (nbr >= base_len)
        ft_putul_base(nbr / base_len, base);
    ft_putchar(base[nbr % base_len]);
}