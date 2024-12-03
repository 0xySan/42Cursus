/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:01 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/03 12:57:30 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_simulation(t_buffet *buffet)
{
	unsigned int	i;

	buffet->start_time = get_time_in_ms() + (buffet->nb_philos * 20);
	i = 0;
	while (i < buffet->nb_philos)
	{
		if (pthread_create(&buffet->philos[i]->thread, NULL,
				&philosopher, buffet->philos[i]) != 0)
			return (handle_ierrors(buffet, THREAD_ERR));
		i++;
	}
	if (buffet->nb_philos > 1)
		if (pthread_create(&buffet->death, NULL,
				&death, buffet) != 0)
			return (handle_ierrors(buffet, THREAD_ERR));
	return (1);
}

static void	stop_simulation(t_buffet *buffet)
{
	unsigned int	i;

	i = 0;
	while (i < buffet->nb_philos)
		pthread_join(buffet->philos[i++]->thread, NULL);
	if (buffet->nb_philos > 1)
		pthread_join(buffet->death, NULL);
	destroy_mutexes(buffet);
	free_buffet(buffet);
}

int	main(int argc, char **argv)
{
	t_buffet	*buffet;

	buffet = NULL;
	if (argc < 5 || argc > 6)
		return (handle_ierrors(buffet, 6));
	if (is_valid_input(argv))
		return (EXIT_FAILURE);
	buffet = init_buffet(argc, argv);
	if (!buffet)
		return (EXIT_FAILURE);
	if (!start_simulation(buffet))
		return (EXIT_FAILURE);
	stop_simulation(buffet);
	return (EXIT_SUCCESS);
}
