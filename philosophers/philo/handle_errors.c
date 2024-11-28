/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:31:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/28 16:42:14 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_handle_errors(int error, va_list args)
{
	if (error == 1)
	{
		printf("Invalid number_of_philosophers.\nThe number of philosophers ");
		printf("is supposed to be higher than 0 and lower than 200.\n");
		printf("Your number : %s, doesn't follow those rules.\n",
			va_arg(args, char *));
	}
}

int	handle_errors(int error, ...)
{
	va_list	args;

	va_start(args, error);
	_handle_errors(error, args);
	va_end(args);
	return (1);
}
