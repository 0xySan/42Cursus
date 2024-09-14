/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:31:52 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/14 14:05:28 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    if(dest < src)
        return ft_memcpy(dest, src, n);
    else
        return ft_memrcpy(dest, src, n);
}

#include <stdio.h>
#include<string.h>

int main()
{
    char ok[] = "\0helloo";
    char ok2[] = "\0helloo";

    ft_memmove(ok, ok + 2, 4);
    memmove(ok2, ok2 + 2, 4);
    printf("%s\n%s\n", ok, ok2);
}