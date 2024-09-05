/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:33:33 by oxysan            #+#    #+#             */
/*   Updated: 2024/09/05 17:28:18 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr(char c, char *str)
{
	unsigned int	start;

	if (!str)
		return (0);
	start = -1;
	while (str[++start])
	{
		if (str[start] == c)
			return (1);
	}
	return (0);
}
