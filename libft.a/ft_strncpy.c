/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:07:49 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/09 18:07:50 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	v;

	if (!src)
		return ;
	v = 0;
	while (v < n && src[v])
	{
		dest[v] = src[v];
		v++;
	}
	dest[v] = '\0';
}