/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 04:28:20 by oxy               #+#    #+#             */
/*   Updated: 2024/09/05 19:19:51 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	start;

	if (n <= 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	start = -1;
	while (++start < n - 1 && s1[start])
	{
		if (s1[start] != s2[start])
			return (s1[start] - s2[start]);
	}
	return (s1[start] - s2[start]);
}