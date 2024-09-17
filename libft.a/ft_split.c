/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:33:33 by oxysan            #+#    #+#             */
/*   Updated: 2024/09/17 18:08:36 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int is_delimiter(char str, char c)
{
	return (str == c || str == '\0');
}

int count_words(char const *str, char c)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (!is_delimiter(*str, c) && !in_word++)
			count++;
		else
			in_word = 0;
		str++;
	}
	return (count);
}

char *copy_word(char const *str, char c)
{
	int len;
	int i;

	len = 0;
	while (!is_delimiter(str[len], c))
		len++;
	char *word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return NULL;
	i = -1;
	while (++i < len)
		word[i] = str[i];
	word[len] = '\0';
	return (word);
}

char **ft_split(char const *str, char c)
{
	int word_count;
	int index;
	char **result;

	word_count = count_words(str, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return NULL;
	index = 0;
	while (*str)
	{
		if (!is_delimiter(*str, c))
		{
			result[index++] = copy_word(str, c);
			while (*str && !is_delimiter(*str, c))
				str++;
		}
		else
			str++;
	}
	result[index] = NULL;
	return (result);
}


int main()
{
	printf("%s", ft_split("Hello World !", ' ')[0]);
}