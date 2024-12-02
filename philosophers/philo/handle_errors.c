/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:51:47 by etaquet           #+#    #+#             */
/*   Updated: 2024/12/02 10:09:30 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_handle_errors_1(int error, va_list args)
{
	if (error == 1)
	{
		printf("Invalid number_of_philosophers.\nThe number of philosophers ");
		printf("is supposed to be higher than 0 and lower than 200 and must ");
		printf("contain only digits.\nYour arg : %s%s",
			va_arg(args, char *), ", doesn't follow those rules.\n");
	}
	if (error == 2)
	{
		printf("Invalid time_to_die.\nThe time to die ");
		printf("is supposed to be higher than 60 and must contain only ");
		printf("digits.\nYour arg : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
	if (error == 3)
	{
		printf("Invalid time_to_eat.\nThe time to eat ");
		printf("is supposed to be higher than 60 and must contain only ");
		printf("digits.\nYour arg : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
}

void	_handle_errors_2(int error, va_list args)
{
	if (error == 4)
	{
		printf("Invalid time_to_sleep.\nThe time to sleep ");
		printf("is supposed to be higher than 60 and must contain only ");
		printf("digits.\nYour arg : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
	if (error == 5)
	{
		printf("Invalid number_of_times_each_philosopher_must_eat.\nThe num");
		printf("ber of times each philosopher must eat must contain only ");
		printf("digits.\nYour arg : %s, doesn't follow this rule.\n",
			va_arg(args, char *));
	}
	if (error == 6)
	{
		printf("usage: ./philo <number_of_philosophers> ");
		printf("<time_to_die> <time_to_eat> <time_to_sleep> ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
	}
	if (error == MALLOC_ERR)
		printf(" error: Could not allocate memory.\n");
	if (error == THREAD_ERR)
		printf(" error: Could not create thread.\n");
}

int	handle_ierrors(t_table *table, int error, ...)
{
	va_list	args;

	va_start(args, error);
	printf("philo: ");
	_handle_errors_1(error, args);
	_handle_errors_2(error, args);
	va_end(args);
	if (table != NULL)
		free_table(table);
	return (1);
}

void	*handle_verrors(t_table *table, int error, ...)
{
	va_list	args;

	va_start(args, error);
	printf("philo: ");
	_handle_errors_1(error, args);
	_handle_errors_2(error, args);
	if (error == MUTEX_ERR)
		printf(" error: Could not create mutex.\n");
	va_end(args);
	if (table != NULL)
		free_table(table);
	return (NULL);
}
