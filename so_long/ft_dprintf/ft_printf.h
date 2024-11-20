/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:45:26 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/20 13:14:25 by etaquet          ###   ########.fr       */
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

int		ft_putstr_fd(char *str, int fd);
int		ft_count_unsigned(unsigned int nb);
int		ft_putchar_fd(int c, int fd);
int		ft_utoa(unsigned int nb, int fd);
void	ft_ultoa(unsigned long nbr, const char *base, int *len, int fd);
void	ft_ltoa(long nbr, const char *base, int *len, int fd);
int		ft_ptoa(void *ptr, int fd);
int		ft_itoa(int n, int fd);
int		ft_dprintf(int fd, const char *str, ...);

typedef struct s_val
{
	int	len;
	int	start;
	int	fd;
}	t_val;

#endif