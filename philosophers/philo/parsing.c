/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:00 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/29 16:46:42 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	contains_only_digits(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	size_t	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		nb = nb * 10 + (str[i++] - '0');
	if (nb > 2147483647)
		return (-1);
	return ((int)nb);
}

int	is_valid_input(char **argv)
{
	if (!contains_only_digits(argv[1]) || ft_atoi(argv[1]) > 200
		|| ft_atoi(argv[1]) < 0)
		return (handle_errors(1, argv[1]));
	if (!contains_only_digits(argv[2]) || ft_atoi(argv[2]) < 60)
		return (handle_errors(2, argv[2]));
	if (!contains_only_digits(argv[3]) || ft_atoi(argv[3]) < 60)
		return (handle_errors(3, argv[3]));
	if (!contains_only_digits(argv[4]) || ft_atoi(argv[4]) < 60)
		return (handle_errors(4, argv[4]));
	if (argv[5])
		if (!contains_only_digits(argv[5]))
			return (handle_errors(5, argv[5]));
	return (0);
}
