/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:09 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 09:51:55 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_sim_stop_flag(t_table *table, int state)
{
	pthread_mutex_lock(&table->sim_stop_lock);
	table->sim_stop = state;
	pthread_mutex_unlock(&table->sim_stop_lock);
}

int	has_simulation_stopped(t_table *table)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop == 1)
		result = 1;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (result);
}

static int	philo_ate_enough(t_philo *philo)
{
	time_t	time;

	time = get_time_in_ms();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		set_sim_stop_flag(philo->table, 1);
		write_status(philo, 1, IS_DEAD);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (1);
	}
	return (0);
}

static int	all_philos_ate_enough(t_table *table)
{
	unsigned int	i;
	int				all_ate_enough;

	all_ate_enough = 1;
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_time_lock);
		if (philo_ate_enough(table->philos[i]))
			return (1);
		if (table->must_eat_count != -1)
			if (table->philos[i]->last_meal_time
				< (unsigned)table->must_eat_count)
				all_ate_enough = 0;
		pthread_mutex_unlock(&table->philos[i]->meal_time_lock);
		i++;
	}
	if (table->must_eat_count != -1 && all_ate_enough == 1)
	{
		set_sim_stop_flag(table, 1);
		return (1);
	}
	return (0);
}

void	*death(void *data)
{
	t_table			*table;

	table = (t_table *)data;
	if (table->must_eat_count == 0)
		return (NULL);
	set_sim_stop_flag(table, 0);
	sim_start_delay(table->start_time);
	while (1)
	{
		if (all_philos_ate_enough(table) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
