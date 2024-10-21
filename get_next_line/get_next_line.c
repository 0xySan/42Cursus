/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:43:11 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/21 18:43:25 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*result;

	len1 = 0;
	len2 = 0;
	i = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	i--;
	while (++i < len1)
		result[i] = s1[i];
	i--;
	while (++i < len1 + len2)
		result[i] = s2[i - len1];
	result[i] = '\0';
	return (result);
}

char	*get_leftover_if_no_newline(char **leftover)
{
	char	*temp2;

	if (ft_strlen(*leftover) > 0)
	{
		temp2 = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
		return (temp2);
	}
	return (NULL);
}

int	read_from_fd(int fd, char **leftover, char *buff)
{
	int		ret;
	char	*temp;

	ret = BUFFER_SIZE;
	while (ft_strchr(*leftover, '\n') == 0 && ret == BUFFER_SIZE)
	{
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		temp = ft_strjoin(*leftover, buff);
		free(*leftover);
		*leftover = temp;
	}
	return (ret);
}

char	*get_line_from_leftover(char **leftover)
{
	char	*temp;
	char	*temp2;
	size_t	len;
	char	*old_leftover;

	if (ft_strchr(*leftover, '\n') != NULL)
	{
		temp = ft_strchr(*leftover, '\n');
		len = temp - *leftover + 1;
		temp2 = ft_substr(*leftover, 0, len);
		old_leftover = *leftover;
		*leftover = ft_substr(*leftover, len, ft_strlen(*leftover) - len);
		free(old_leftover);
		return (temp2);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*leftover = NULL;
	char		*temp2;

	if (!leftover)
	{
		leftover = malloc(1);
		if (!leftover)
			return (NULL);
		leftover[0] = '\0';
	}
	temp2 = get_line_from_leftover(&leftover);
	if (temp2)
		return (temp2);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_from_fd(fd, &leftover, buff);
	free(buff);
	temp2 = get_line_from_leftover(&leftover);
	if (temp2)
		return (temp2);
	temp2 = get_leftover_if_no_newline(&leftover);
	if (!ft_strlen(leftover))
	{
		free(leftover);
		leftover = 0;
	}
	return (temp2);
}

int	main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	char *temp;

	while ((temp = get_next_line(0)))
	{
		dprintf(1, "%s", temp);
		free(temp);
	}
	free(temp);
	close(fd);
	return 0;
}
