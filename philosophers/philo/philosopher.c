/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:20:28 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 10:11:12 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_routine(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up)
	{
		if (has_simulation_stopped(table))
			break ;
		usleep(100);
	}
}

static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
	write_status(philo, 0, TOOK_L_FORK);
	pthread_mutex_lock(&philo->table->forks[philo->fork[1]]);
	write_status(philo, 0, TOOK_R_FORK);
	write_status(philo, 0, IS_EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	sleep_routine(philo->table, philo->table->time_to_eat);
	if (has_simulation_stopped(philo->table) == 0)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->last_meal_time += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	write_status(philo, 0, IS_SLEEPING);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
	sleep_routine(philo->table, philo->table->time_to_sleep);
}

static void	think_routine(t_philo *philo, int silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->table->time_to_die
			- (get_time_in_ms() - philo->last_meal)
			- philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == 1)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == 0)
		write_status(philo, 0, IS_THINKING);
	sleep_routine(philo->table, time_to_think);
}

static void	*lone_philo_route(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
	write_status(philo, 0, TOOK_L_FORK);
	sleep_routine(philo->table, philo->table->time_to_die);
	write_status(philo, 0, IS_DEAD);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
	return (NULL);
}

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_time_lock);
	sim_start_delay(philo->table->start_time);
	if (philo->table->nb_philos == 1)
		return (lone_philo_route(philo));
	else if (philo->id % 2)
		think_routine(philo, 1);
	while (has_simulation_stopped(philo->table) == 0)
	{
		eat_sleep_routine(philo);
		think_routine(philo, 0);
	}
	return (NULL);
}
