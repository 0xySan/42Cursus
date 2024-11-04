/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:35:05 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/22 19:32:08 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	start;

	if (!str)
		return (write(1, "(null)", 6));
	start = 0;
	while (str[start])
		write(1, &str[start++], 1);
	return (start);
}
