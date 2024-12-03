/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:46:01 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:56:59 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdarg.h>

# define IS_DEAD		0
# define IS_EATING		1
# define IS_SLEEPING	2
# define IS_THINKING	3
# define TOOK_L_FORK	4
# define TOOK_R_FORK	5

# define MALLOC_ERR		7
# define THREAD_ERR		8
# define MUTEX_ERR		9

typedef struct s_philo	t_philo;

typedef struct s_buffet
{
	time_t			start_time;
	unsigned int	nb_philos;
	pthread_t		death;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat_count;
	int				sim_stop;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			**philos;
}	t_buffet;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		last_meal_time;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				last_meal;
	t_buffet			*buffet;
}	t_philo;

int				is_valid_input(char **argv);
int				ft_atoi(char *str);
t_buffet		*init_buffet(int argc, char **argv);
void			*philosopher(void *data);
time_t			get_time_in_ms(void);
void			sim_start_delay(time_t start_time);
void			write_status(t_philo *philo, int death_report, int status);
void			*death(void *data);
int				has_simulation_stopped(t_buffet *buffet);
void			*free_buffet(t_buffet *buffet);
void			destroy_mutexes(t_buffet *buffet);
int				handle_ierrors(t_buffet *buffet, int error, ...);
void			*handle_verrors(t_buffet *buffet, int error, ...);

#endif
