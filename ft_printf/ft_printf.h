/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:45:26 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/05 10:33:12 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_utoa(unsigned int nb);
int	    ft_ultoa(unsigned long nbr, const char *base);
int		ft_ptoa(void *ptr);
int		ft_itoa(int n);
int		ft_printf(const char *str, ...);

#endif