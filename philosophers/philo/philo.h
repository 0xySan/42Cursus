/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:25 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/29 11:40:09 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdarg.h>

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				number_of_philo;
	int				total_eaten;
	int				check_dead;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		handle_errors(int error, ...);
void	init_philos(t_philo *philos, char **argv);
long	ft_atol(char *nptr);
void	ft_mutex_init(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);

#endif