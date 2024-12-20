/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:34:12 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:57:17 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time_in_ms() - philo->buffet->start_time,
		philo->id + 1, str);
}

void	write_status(t_philo *philo, int death_report, int status)
{
	pthread_mutex_lock(&philo->buffet->write_lock);
	if (has_simulation_stopped(philo->buffet) == 1 && death_report == 0)
	{
		pthread_mutex_unlock(&philo->buffet->write_lock);
		return ;
	}
	if (status == IS_DEAD)
		print_status(philo, "died");
	else if (status == IS_EATING)
		print_status(philo, "is eating");
	else if (status == IS_SLEEPING)
		print_status(philo, "is sleeping");
	else if (status == IS_THINKING)
		print_status(philo, "is thinking");
	else if (status == TOOK_L_FORK || status == TOOK_R_FORK)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->buffet->write_lock);
}
