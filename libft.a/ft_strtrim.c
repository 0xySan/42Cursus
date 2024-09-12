/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:44:30 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/12 22:25:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_int_strchr(const char *str, int c)
{
        unsigned int    start;

        if (!str)
                return (0);
        start = -1;
        while (str[++start])
        {
                if (str[start] == c)
                {
                        return (1);
                }
        }
        return (0);
}

int trim_len(char const *s1, char const *set)
{
    int start;
    int temp;
    int len;

    len = 0;
    start = 0;
    while (s1[start++])
    {
        temp = 0;
        while (set[temp++])
            if(s1[start] != set[temp])
                len++;
    }
    return len;
}

#include <stdio.h>

char *ft_strtrim(char const *s1, char const *set)
{
    char *r_value;

    r_value = malloc(sizeof(char) * (trim_len(s1, set) + 1));
    if (r_value == NULL)
        return (NULL);
    printf("%d", ft_int_strchr(s1, set[0]));µ
    return "yolo";
}

int main()
{
    ft_strtrim("Hello World!", "oe");
}