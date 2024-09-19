/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:42:29 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/18 18:42:43 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsigned(unsigned int nb)
{
	unsigned int	nb_count;
	unsigned int	n_tempo;
	unsigned int	nb_tempo;

	nb_count = ft_count_unsigned(nb)+1;
	while (nb_count-- > 0)
	{
		n_tempo = nb_count;
		nb_tempo = nb;
		while (n_tempo--)
			nb_tempo /= 10;
		ft_putchar(nb_tempo % 10 + '0');
	}
}