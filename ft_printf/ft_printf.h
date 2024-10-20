/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:45:26 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 13:33:16 by etaquet          ###   ########.fr       */
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

void	ft_putstr(char *str);
void	ft_putchar(int c);
void	ft_utoa(unsigned int nb);
int		ft_count_unsigned(unsigned int nb);
void	ft_ultoa(unsigned long nbr, const char *base);
void	ft_ltoa(long nbr, const char *base);
void	ft_ptoa(void *ptr);
int		ft_printf(const char *str, ...);

#endif