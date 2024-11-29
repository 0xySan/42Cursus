/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:00 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/29 16:09:34 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time_in_ms() - philo->table->start_time,
		philo->id + 1, str);
}

void	write_status(t_philo *philo, int death_report, int status)
{
	pthread_mutex_lock(&philo->table->write_lock);
	if (has_simulation_stopped(philo->table) == 1 && death_report == 0)
	{
		pthread_mutex_unlock(&philo->table->write_lock);
		return ;
	}
	if (status == 0)
		print_status(philo, "died");
	else if (status == 1)
		print_status(philo, "is eating");
	else if (status == 2)
		print_status(philo, "is sleeping");
	else if (status == 3)
		print_status(philo, "is thinking");
	else if (status == 4 || status == 5)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->write_lock);
}
