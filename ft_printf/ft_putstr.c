/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:35:05 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 13:28:54 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	start;

	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	start = 0;
	while (str[start])
		write(1, &str[start++], 1);
}
