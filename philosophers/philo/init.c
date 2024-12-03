/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:54 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:56:47 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_forks(t_buffet *buffet)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * buffet->nb_philos);
	if (!forks)
		return (handle_verrors(buffet, MALLOC_ERR));
	i = 0;
	while (i < buffet->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (handle_verrors(buffet, MALLOC_ERR));
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->buffet->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->buffet->nb_philos;
		philo->fork[1] = philo->id;
	}
}

static t_philo	**init_philosophers(t_buffet *buffet)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * buffet->nb_philos);
	if (!philos)
		return (handle_verrors(buffet, MALLOC_ERR));
	i = 0;
	while (i < buffet->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (handle_verrors(buffet, MALLOC_ERR));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (handle_verrors(buffet, MUTEX_ERR));
		philos[i]->buffet = buffet;
		philos[i]->id = i;
		philos[i]->last_meal_time = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static int	init_global_mutexes(t_buffet *buffet)
{
	buffet->forks = init_forks(buffet);
	if (!buffet->forks)
		return (0);
	if (pthread_mutex_init(&buffet->sim_stop_lock, 0) != 0)
		return (handle_ierrors(buffet, MUTEX_ERR));
	if (pthread_mutex_init(&buffet->write_lock, 0) != 0)
		return (handle_ierrors(buffet, MUTEX_ERR));
	return (1);
}

t_buffet	*init_buffet(int argc, char **argv)
{
	t_buffet	*buffet;

	buffet = malloc(sizeof(t_buffet) * 1);
	if (!buffet)
		return (handle_verrors(buffet, MALLOC_ERR));
	buffet->nb_philos = ft_atoi(argv[1]);
	buffet->time_to_die = ft_atoi(argv[2]);
	buffet->time_to_eat = ft_atoi(argv[3]);
	buffet->time_to_sleep = ft_atoi(argv[4]);
	buffet->must_eat_count = -1;
	if (argc == 6)
		buffet->must_eat_count = ft_atoi(argv[5]);
	buffet->philos = init_philosophers(buffet);
	if (!buffet->philos)
		return (NULL);
	if (!init_global_mutexes(buffet))
		return (NULL);
	buffet->sim_stop = 0;
	return (buffet);
}
