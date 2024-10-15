/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:43:02 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/19 14:15:18 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char *ft_substr(char const *s, unsigned int start, long len);
char	*ft_strchr(const char *s, int c);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#endif