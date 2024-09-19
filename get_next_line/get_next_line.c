/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:43:11 by etaquet           #+#    #+#             */
/*   Updated: 2024/09/19 14:16:29 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void    *ft_memset(void *s, int c, size_t n)
{
	size_t start;

	start = 0;
	while(start < n)
		((char*) s)[start++] = c;
	return s;
}

int	ft_strlen(const char *str)
{
	size_t	val;

	val = 0;
	while (str[val])
		val++;
	return (val);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		start;

	if (!src)
		return (0);
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	start = -1;
	while (src[++start])
		dest[start] = src[start];
	dest[start] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

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

char *ft_substr(char const *s, unsigned int start, long len)
{
	char *r_value;
	r_value = malloc(sizeof(char) * (len + 1));
	if (r_value == NULL)
		return (NULL);
	ft_strncpy(r_value, s+start, len);
	return r_value;
}

char	*ft_strchr(const char *s, int c)
{
	size_t	start;

	if (!s)
		return (0);
	start = -1;
	while (s[++start])
	{
		if (s[start] == c)
			return ((char*)&s[start]);
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}

char *get_leftover_if_no_newline(char **leftover)
{
    char *temp2;

    if (ft_strlen(*leftover) > 0)
    {
        temp2 = ft_strdup(*leftover);
        free(*leftover);
        *leftover = NULL;
        return temp2;
    }
    return NULL;
}

int read_from_fd(int fd, char **leftover, char *buff)
{
    int ret = BUFFER_SIZE;
    char *temp;

    while (ft_strchr(*leftover, '\n') == 0 && ret == BUFFER_SIZE)
    {
        ft_memset(buff, 0, BUFFER_SIZE + 1);
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret <= 0)
            break;
        temp = ft_strjoin(*leftover, buff);
        free(*leftover);
        *leftover = temp;
    }
    return ret;
}

char *get_line_from_leftover(char **leftover)
{
    char *temp;
    char *temp2;
    size_t len;
	char *old_leftover;

    if ((temp = ft_strchr(*leftover, '\n')) != NULL)
    {
        len = temp - *leftover + 1;
        temp2 = ft_substr(*leftover, 0, len);
        old_leftover = *leftover;
        *leftover = ft_substr(*leftover, len, ft_strlen(*leftover) - len);
        free(old_leftover);
        return temp2;
    }
    return NULL;
}

char *get_next_line(int fd)
{
    char *buff;
    static char *leftover = NULL;
    char *temp2;

    if (!leftover)
    {
        leftover = malloc(1);
        if (!leftover)
            return NULL;
        leftover[0] = '\0';
    }
    temp2 = get_line_from_leftover(&leftover);
    if (temp2)
        return temp2;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return NULL;
    read_from_fd(fd, &leftover, buff);
    free(buff);
    temp2 = get_line_from_leftover(&leftover);
    if (temp2)
        return temp2;
    return get_leftover_if_no_newline(&leftover);
}





int main(int argc, char **argv)
{
    (void)argc;
    int fd = open(argv[1], O_RDONLY);
    char *temp;

    while ((temp = get_next_line(fd)))
    {
        dprintf(1, "%s", temp);
        free(temp);
    }
    close(fd);
    return 0;
}



// test
