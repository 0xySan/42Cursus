/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:45:26 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/19 13:23:47 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
typedef unsigned long size_t;
void ft_putstr(char *str);
void ft_putchar(int c);
int	ft_count_nb(int nb, int len);
void	ft_putunsigned(unsigned int nb);
int	ft_count_unsigned(unsigned int nb);
void    ft_putul_base(unsigned long nbr, const char *base);
void    ft_putl_base(long nbr, const char *base);
void    ft_putpointer(void *ptr);


#endif