/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:09 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:57:41 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_sim_stop_flag(t_buffet *buffet, int state)
{
	pthread_mutex_lock(&buffet->sim_stop_lock);
	buffet->sim_stop = state;
	pthread_mutex_unlock(&buffet->sim_stop_lock);
}

int	has_simulation_stopped(t_buffet *buffet)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&buffet->sim_stop_lock);
	if (buffet->sim_stop == 1)
		result = 1;
	pthread_mutex_unlock(&buffet->sim_stop_lock);
	return (result);
}

static int	philo_ate_enough(t_philo *philo)
{
	time_t	time;

	time = get_time_in_ms();
	if ((time - philo->last_meal) >= philo->buffet->time_to_die)
	{
		set_sim_stop_flag(philo->buffet, 1);
		write_status(philo, 1, IS_DEAD);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (1);
	}
	return (0);
}

static int	all_philos_ate_enough(t_buffet *buffet)
{
	unsigned int	i;
	int				all_ate_enough;

	all_ate_enough = 1;
	i = 0;
	while (i < buffet->nb_philos)
	{
		pthread_mutex_lock(&buffet->philos[i]->meal_time_lock);
		if (philo_ate_enough(buffet->philos[i]))
			return (1);
		if (buffet->must_eat_count != -1)
			if (buffet->philos[i]->last_meal_time
				< (unsigned)buffet->must_eat_count)
				all_ate_enough = 0;
		pthread_mutex_unlock(&buffet->philos[i]->meal_time_lock);
		i++;
	}
	if (buffet->must_eat_count != -1 && all_ate_enough == 1)
	{
		set_sim_stop_flag(buffet, 1);
		return (1);
	}
	return (0);
}

void	*death(void *data)
{
	t_buffet			*buffet;

	buffet = (t_buffet *)data;
	if (buffet->must_eat_count == 0)
		return (NULL);
	set_sim_stop_flag(buffet, 0);
	sim_start_delay(buffet->start_time);
	while (1)
	{
		if (all_philos_ate_enough(buffet) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
