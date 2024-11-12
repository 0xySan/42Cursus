/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:32:23 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/12 15:27:05 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	spe_strlen(char *str)
{
	size_t	val;

	if (!str)
		return (0);
	val = 0;
	while (str[val] && str[val] != '\n')
		val++;
	return (val);
}

void	ft_malloc_map(t_init_map *so_long)
{
	int	i;

	so_long->map = malloc((so_long->length) * sizeof(char *));
	i = 0;
	while (i < so_long->length)
		so_long->map[i++] = malloc((so_long->height) * sizeof(char));
}

void	ft_write_map(t_init_map *so_long)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open(so_long->fn, O_RDONLY);
	line = get_next_line(fd);
	ft_malloc_map(so_long);
	j = 0;
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			so_long->map[i][j] = line[i];
			i++;
		}
		j++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	ft_read_map(t_init_map *so_long)
{
	char	*line;
	int		fd;

	fd = open(so_long->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nLine/File not found.\n"),
			ft_free(so_long), exit(EXIT_FAILURE));
	so_long->length = spe_strlen(line);
	while (line)
	{
		if (spe_strlen(line) != so_long->length)
			so_long->error_type = 8;
		so_long->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
	if (so_long->error_type)
		return (ft_printf("Error\n%s\nError type : %d\n",
				"Lenght of line isn't the same everywhere.",
				so_long->error_type),
			ft_free(so_long), exit(EXIT_FAILURE));
	ft_write_map(so_long);
}
