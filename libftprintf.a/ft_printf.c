/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:08:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/21 02:27:32 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		start;
	
	start = 0;
	va_start(args, str);
	while(str[start])
		if(str[start] == '%')
		{
			if(str[start+1] == '%') write(1,"%%", 1);
			if(str[start+1] == 'c') ft_putchar(va_arg(args, int));
			if(str[start+1] == 's') ft_putstr(va_arg(args, char*));
			if(str[start+1] == 'd' || str[start+1] == 'i') 
				ft_ltoa(va_arg(args, int), "0123456789");
			if(str[start+1] == 'x') 
				ft_ltoa(va_arg(args, unsigned int), "0123456789abcdef");
			if(str[start+1] == 'X')
				ft_ltoa(va_arg(args, unsigned int), "0123456789ABCDEF");
			if(str[start+1] == 'u') ft_utoa(va_arg(args, unsigned int));
			if(str[start+1] == 'p') ft_ptoa(va_arg(args, void*));
			start+=2;
		}
		else
			write(1,&str[start++],1);
	va_end(args);
	return (0);
}

int main() {
	char *test;
	ft_printf("%%%%\n%c\n%s\n%d\n%i\n%x\n%X\n%u\n%p\n\n\n", 0, "t", 0, 0, 0, 0, 123, test);
	printf("%%%%\n%c\n%s\n%d\n%i\n%x\n%X\n%u\n%p\n", 0, "t", 0, 0, 0, 0, 123, test);
	return 0;
}
