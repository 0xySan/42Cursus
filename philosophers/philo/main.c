/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:01 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 10:07:43 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_simulation(t_table *table)
{
	unsigned int	i;

	table->start_time = get_time_in_ms() + (table->nb_philos * 20);
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&philosopher, table->philos[i]) != 0)
			return (handle_ierrors(table, THREAD_ERR));
		i++;
	}
	if (table->nb_philos > 1)
		if (pthread_create(&table->death, NULL,
				&death, table) != 0)
			return (handle_ierrors(table, THREAD_ERR));
	return (1);
}

static void	stop_simulation(t_table	*table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
		pthread_join(table->philos[i++]->thread, NULL);
	if (table->nb_philos > 1)
		pthread_join(table->death, NULL);
	destroy_mutexes(table);
	free_table(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc < 5 || argc > 6)
		return (handle_ierrors(table, 6));
	if (is_valid_input(argv))
		return (EXIT_FAILURE);
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	if (!start_simulation(table))
		return (EXIT_FAILURE);
	stop_simulation(table);
	return (EXIT_SUCCESS);
}
