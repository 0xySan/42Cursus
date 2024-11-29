/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:05:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/29 12:27:31 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (ft_atol(argv[1]) > 200 || ft_atol(argv[1]) <= 0
		|| check_if_number(argv[1]))
		return (handle_errors(1, argv[1]));
	if (ft_atol(argv[2]) < 60 || check_if_number(argv[2]))
		return (handle_errors(2, argv[2]));
	if (ft_atol(argv[3]) < 60 || check_if_number(argv[3]))
		return (handle_errors(3, argv[3]));
	if (ft_atol(argv[4]) < 60 || check_if_number(argv[4]))
		return (handle_errors(4, argv[4]));
	return (0);
}


int	main(int argc, char **argv)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (argc < 5 || argc > 6)
		return (printf("Invalid arguments.\nUse something like this : %s %s\n",
				"./philo number_of_philosophers time_to_die time_to_eat",
				"time_to_sleep [number_of_times_each_philosopher_must_eat]"));
	if (check_valid_args(argv))
		return (1);
	philos = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philos || !forks || !death)
		return (1);
	init_philos(philos, argv);
	ft_mutex_init(philos, forks, death);
}
