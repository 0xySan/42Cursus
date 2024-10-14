/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:33:33 by oxysan            #+#    #+#             */
/*   Updated: 2024/09/21 02:25:18 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int count_words(const char *s, char c) 
{
    int count;
	int in_word;

	count = 0;
	in_word= 0;
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
    return count;
}

char *extract_word(const char *s, int *index, char c) 
{
    int start;
	int len;
	char *word;

	start = *index;

    while (s[*index] && s[*index] !=c) 
        (*index)++;
	len = *index - start;
	word = malloc(len + 1);
    if (word) 
    {
        ft_strncpy(word, s + start, len);
        word[len] = '\0';
    }
    return word;
}

void split_words(char const *s, char c, char **result) 
{
    int index;
	int word_index;

	index = 0;
	word_index = 0;
    while (s[index]) 
    {
        if (s[index] != c) 
            result[word_index++] = extract_word(s, &index, c);
        else 
            index++;
    }
}

char **ft_split(char const *s, char c) 
{
	int word_count;
	char **result;

    if (!s) 
        return NULL;
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
    if (!result) 
        return NULL;
    split_words(s, c, result);
    return result;
}

int main() 
{
    char **result;
    const char *s = "Hello, world! This is a test.";
    char delimiter = ' ';

    result = ft_split(s, delimiter);

    for (int i = 0; result && result[i]; i++) 
    {
        printf("Word %d: %s\n", i + 1, result[i]);
        free(result[i]); // Free each word
    }
    free(result); // Free the array

    return 0;
}
