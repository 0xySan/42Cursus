/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:09:25 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/09 17:45:53 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_count_nb(int nb)
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

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strcat(char *dest, char src)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0')
		++i;
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int nb)
{
	int	nb_count;
	int	n_tempo;
	int	nb_tempo;
    char *r_value;

    if (nb < 0)
    {
        if (nb == -2147483648)
        {
            r_value = malloc(sizeof(int) * (ft_count_nb(nb) + 2));
            return ft_strcpy(r_value, "-2147483648");
        }
        nb = -nb;
        r_value = malloc(sizeof(int) * (ft_count_nb(nb) + 2));
        ft_strcat(r_value, '-');
    }
    else
        r_value = malloc(sizeof(int) * (ft_count_nb(nb) + 1));
	nb_count = ft_count_nb(nb)+1;
	while (nb_count-- > 0)
	{
		n_tempo = nb_count;
		nb_tempo = nb;
		while (n_tempo--)
			nb_tempo /= 10;
		ft_strcat(r_value, (nb_tempo % 10 + '0'));
	}
    return r_value;
}