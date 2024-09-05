/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:49:20 by oxy               #+#    #+#             */
/*   Updated: 2024/09/05 17:42:44 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	start;
	int	signe;
	int	value;

	signe = 1;
	start = 0;
	while (str[start] == ' ' || (str[start] >= '\t' && str[start] <= '\r'))
		start++;
	value = 0;
	while ((str[start] == '+' || str[start] == '-'))
	{
		if (str[start] == '-')
			signe *= -1;
		start++;
	}
	while (str[start] >= '0' && str[start] <= '9')
		value = value * 10 + str[start++] - '0';
	return (value * signe);
}
