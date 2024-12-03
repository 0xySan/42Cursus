/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:54:02 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:57:05 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_buffet(t_buffet *buffet)
{
	unsigned int	i;

	if (!buffet)
		return (NULL);
	if (buffet->forks != NULL)
		free(buffet->forks);
	if (buffet->philos != NULL)
	{
		i = 0;
		while (i < buffet->nb_philos)
		{
			if (buffet->philos[i] != NULL)
				free(buffet->philos[i]);
			i++;
		}
		free(buffet->philos);
	}
	free(buffet);
	return (NULL);
}

void	destroy_mutexes(t_buffet *buffet)
{
	unsigned int	i;

	i = 0;
	while (i < buffet->nb_philos)
	{
		pthread_mutex_destroy(&buffet->forks[i]);
		pthread_mutex_destroy(&buffet->philos[i]->meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&buffet->write_lock);
	pthread_mutex_destroy(&buffet->sim_stop_lock);
}

time_t	get_time_in_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sim_start_delay(time_t start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}
