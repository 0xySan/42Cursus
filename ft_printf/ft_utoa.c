/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:42:29 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/23 14:46:03 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_utoa(unsigned int nb)
{
	unsigned int	nb_count;
	unsigned int	n_tempo;
	unsigned int	nb_tempo;
	int				len;

	nb_count = ft_count_unsigned(nb) + 1;
	len = 0;
	while (nb_count-- > 0)
	{
		n_tempo = nb_count;
		nb_tempo = nb;
		while (n_tempo--)
			nb_tempo /= 10;
		ft_putchar(nb_tempo % 10 + '0');
		len++;
	}
	return (len);
}
