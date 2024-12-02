/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:54 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 10:06:48 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!forks)
		return (handle_verrors(table, MALLOC_ERR));
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (handle_verrors(table, MALLOC_ERR));
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philos;
		philo->fork[1] = philo->id;
	}
}

static t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!philos)
		return (handle_verrors(table, MALLOC_ERR));
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (handle_verrors(table, MALLOC_ERR));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (handle_verrors(table, MUTEX_ERR));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->last_meal_time = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static int	init_global_mutexes(t_table *table)
{
	table->forks = init_forks(table);
	if (!table->forks)
		return (0);
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
		return (handle_ierrors(table, MUTEX_ERR));
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
		return (handle_ierrors(table, MUTEX_ERR));
	return (1);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (handle_verrors(table, MALLOC_ERR));
	table->nb_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat_count = -1;
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	table->philos = init_philosophers(table);
	if (!table->philos)
		return (NULL);
	if (!init_global_mutexes(table))
		return (NULL);
	table->sim_stop = 0;
	return (table);
}
