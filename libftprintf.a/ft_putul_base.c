/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/18 19:18:00 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putul_base(unsigned long nbr, const char *base)
{
    unsigned long   base_len;

    base_len = 0;
    while (base[base_len])
        base_len++;
    if (nbr >= base_len)
        ft_putul_base(nbr / base_len, base);
    ft_putchar(base[nbr % base_len]);
}