/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:08:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/22 19:37:12 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_format(va_list args, const char *str, int *start, int *len)
{
	char	format;

	format = str[*start + 1];
	if (format == '%')
		*len += write(1, "%%", 1);
	else if (format == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_ltoa(va_arg(args, int), "0123456789", len);
	else if (format == 'x')
		ft_ltoa(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (format == 'X')
		ft_ltoa(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (format == 'u')
		*len += ft_utoa(va_arg(args, unsigned int));
	else if (format == 'p')
		*len += ft_ptoa(va_arg(args, void *));
	*start += 2;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		start;
	int		len;

	start = 0;
	len = 0;
	va_start(args, str);
	while (str[start])
	{
		if (str[start] == '%')
			ft_handle_format(args, str, &start, &len);
		else
			len += write(1, &str[start++], 1);
	}
	va_end(args);
	return (len);
}
