/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:55:45 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/29 12:36:11 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	struct timeval	tp;
	size_t			time;

	if (gettimeofday(&tp, NULL) == -1)
		return (-1);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}

void	init_philos(t_philo *philos, char **argv)
{
	int	i;

    i = 0;
	while (i < ft_atol(argv[1]))
	{
		philos->id = i + 1;
		if (argv[5])
			philos->must_eat = ft_atol(argv[5]);
		else
		    philos->must_eat = -1;
		philos->number_of_philo = ft_atol(argv[1]);
		philos->total_eaten = 0;
		philos->check_dead = 0;
		philos->time_to_die = ft_atol(argv[2]);
		philos->time_to_eat = ft_atol(argv[3]);
		philos->time_to_sleep = ft_atol(argv[4]);
		philos->start_time = ft_get_time();
		philos->last_meal = ft_get_time();
		i++;
	}
}

void	ft_mutex_init(t_philo *philos, pthread_mutex_t *forks,
		pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philos->number_of_philo)
	{
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % philos->number_of_philo];
		i++;
	}
	i = 0;
	while (i < philos->number_of_philo)
	{
		pthread_mutex_init(philos[i].left_fork, NULL);
		pthread_mutex_init(philos[i].right_fork, NULL);
		philos[i].death = death;
		i++;
	}
	pthread_mutex_init(philos->death, NULL);
}