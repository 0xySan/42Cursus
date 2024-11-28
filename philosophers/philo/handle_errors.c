/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:31:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/28 17:35:09 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_handle_errors_1(int error, va_list args)
{
	if (error == 1)
	{
		printf("Invalid number_of_philosophers.\nThe number of philosophers ");
		printf("is supposed to be higher than 0 and lower than 200 and must");
		printf("contain only digits.\nYour number : %s%s",
			va_arg(args, char *), ", doesn't follow those rules.\n");
	}
	if (error == 2)
	{
		printf("Invalid number_of_philosophers.\nThe number of philosophers ");
		printf("is supposed to be higher than 60 and must contain only ");
		printf("digits.\nYour number : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
	if (error == 3)
	{
		printf("Invalid number_of_philosophers.\nThe number of philosophers ");
		printf("is supposed to be higher than 60 and must contain only ");
		printf("digits.\nYour number : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
}

void	_handle_errors_2(int error, va_list args)
{
	if (error == 4)
	{
		printf("Invalid number_of_philosophers.\nThe number of philosophers ");
		printf("is supposed to be higher than 60 and must contain only ");
		printf("digits.\nYour number : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
}

int	handle_errors(int error, ...)
{
	va_list	args;

	va_start(args, error);
	_handle_errors_1(error, args);
	_handle_errors_2(error, args);
	va_end(args);
	return (1);
}
