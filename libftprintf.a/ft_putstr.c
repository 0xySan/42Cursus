/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:35:05 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/18 19:32:13 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
