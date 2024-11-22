/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 03:28:58 by etaquet           #+#    #+#             */
/*   Updated: 2024/11/21 03:47:17 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char *s, int *index, char c)
{
	int		start;
	int		len;
	char	*word;

	start = *index;
	while (s[*index] && s[*index] != c)
		(*index)++;
	len = *index - start;
	word = malloc(len + 1);
	if (word)
	{
		ft_strncpy(word, s + start, len);
		word[len] = '\0';
	}
	return (word);
}

static void	split_words(char const *s, char c, char **result)
{
	int	index;
	int	word_index;

	index = 0;
	word_index = 1;
	while (s[index])
	{
		if (s[index] != c)
			result[word_index++] = extract_word(s, &index, c);
		else
			index++;
	}
	result[word_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 2) * sizeof(char *));
	result[0] = "./a.out";
	if (!result)
		return (NULL);
	split_words(s, c, result);
	return (result);
}
