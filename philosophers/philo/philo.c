/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:05:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/28 17:34:32 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *nptr)
{
	int	start;
	int	signe;
	int	value;

	signe = 1;
	start = 0;
	value = 0;
	while (nptr[start] == ' ' || (nptr[start] >= '\t' && nptr[start] <= '\r'))
		start++;
	if (nptr[start] == '-' || nptr[start] == '+')
	{
		if (nptr[start] == '-')
			signe *= -1;
		start++;
	}
	while (nptr[start] >= '0' && nptr[start] <= '9')
		value = value * 10 + nptr[start++] - '0';
	return (value * signe);
}

int	check_if_number(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0
		|| check_if_number(argv[1]))
		return (handle_errors(1, argv[1]));
	if (ft_atoi(argv[2]) < 60 || check_if_number(argv[2]))
		return (handle_errors(2, argv[2]));
	if (ft_atoi(argv[3]) < 60 || check_if_number(argv[3]))
		return (handle_errors(3, argv[3]));
	if (ft_atoi(argv[4]) < 60 || check_if_number(argv[4]))
		return (handle_errors(4, argv[4]));
	return (0);
}


int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Invalid arguments.\nUse something like this : %s %s\n",
				"./philo number_of_philosophers time_to_die time_to_eat",
				"time_to_sleep [number_of_times_each_philosopher_must_eat]"));
	if (check_valid_args(argv))
		return (1);
}
