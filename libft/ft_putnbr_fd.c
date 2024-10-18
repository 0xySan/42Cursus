/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:53:48 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/15 14:24:27 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nb(int nb)
{
	int	value;

	value = 0;
	while (nb > 9)
	{
		nb /= 10;
		value++;
	}
	return (value);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	nb_count;
	int	n_tempo;
	int	nb_tempo;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	nb_count = ft_count_nb(n)+1;
	while (nb_count-- > 0)
	{
		n_tempo = nb_count;
		nb_tempo = n;
		while (n_tempo--)
			nb_tempo /= 10;
		ft_putchar_fd((nb_tempo % 10 + '0'), fd);
	}
}
