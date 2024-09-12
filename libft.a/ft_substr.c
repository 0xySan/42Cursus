/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:34:46 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/12 18:38:25 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *r_value;
    r_value = malloc(sizeof(char) * (len + 1));
    if (r_value == NULL)
        return (NULL);
    ft_strncpy(r_value, s+start, len);
    return r_value;
}