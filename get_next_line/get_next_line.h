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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, long len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*get_leftover_if_no_newline(char **leftover);
int		read_from_fd(int fd, char **leftover, char *buff);
char	*get_line_from_leftover(char **leftover);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif