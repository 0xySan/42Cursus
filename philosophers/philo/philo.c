/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:20:28 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:59:57 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_routine(t_buffet *buffet, time_t sleep_time)
{
	time_t	wake_up_time;

	wake_up_time = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up_time)
	{
		if (has_simulation_stopped(buffet))
			break ;
		usleep(100);
	}
}

static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->buffet->forks[philo->fork[0]]);
	write_status(philo, 0, TOOK_L_FORK);
	pthread_mutex_lock(&philo->buffet->forks[philo->fork[1]]);
	write_status(philo, 0, TOOK_R_FORK);
	write_status(philo, 0, IS_EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	sleep_routine(philo->buffet, philo->buffet->time_to_eat);
	if (has_simulation_stopped(philo->buffet) == 0)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->last_meal_time += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	write_status(philo, 0, IS_SLEEPING);
	pthread_mutex_unlock(&philo->buffet->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->buffet->forks[philo->fork[0]]);
	sleep_routine(philo->buffet, philo->buffet->time_to_sleep);
}

static void	think_routine(t_philo *philo)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->buffet->time_to_die
			- (get_time_in_ms() - philo->last_meal)
			- philo->buffet->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > 600)
		time_to_think = 200;
	write_status(philo, 0, IS_THINKING);
	sleep_routine(philo->buffet, time_to_think);
}

static void	*lone_philo_route(t_philo *philo)
{
	pthread_mutex_lock(&philo->buffet->forks[philo->fork[0]]);
	write_status(philo, 0, TOOK_L_FORK);
	sleep_routine(philo->buffet, philo->buffet->time_to_die);
	write_status(philo, 0, IS_DEAD);
	pthread_mutex_unlock(&philo->buffet->forks[philo->fork[0]]);
	return (NULL);
}

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->buffet->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->buffet->start_time;
	pthread_mutex_unlock(&philo->meal_time_lock);
	sim_start_delay(philo->buffet->start_time);
	if (philo->buffet->nb_philos == 1)
		return (lone_philo_route(philo));
	else if (philo->id % 2)
		usleep(100);
	while (has_simulation_stopped(philo->buffet) == 0)
	{
		eat_sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
