/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:43:01 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/18 18:43:09 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_unsigned(unsigned int nb)
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