/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:08:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 13:28:42 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_format(va_list args, const char *str, int *start)
{
	char	format;

	format = str[*start + 1];
	if (format == '%')
		write(1, "%%", 1);
	else if (format == 'c')
		ft_putchar(va_arg(args, int));
	else if (format == 's')
		ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_ltoa(va_arg(args, int), "0123456789");
	else if (format == 'x')
		ft_ltoa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		ft_ltoa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'u')
		ft_utoa(va_arg(args, unsigned int));
	else if (format == 'p')
		ft_ptoa(va_arg(args, void *));
	*start += 2;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		start;

	start = 0;
	va_start(args, str);
	while (str[start])
	{
		if (str[start] == '%')
			ft_handle_format(args, str, &start);
		else
			write(1, &str[start++], 1);
	}
	va_end(args);
	return (0);
}
