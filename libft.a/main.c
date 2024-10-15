/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:22 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/15 18:07:21 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <string.h>

//// MAIN OF ALL IS... + to lower and to upper
/* int	main(void)
{
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", isalnum('a'));
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", isalpha('a'));
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", isascii('a'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", isdigit('1'));
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", isprint('a'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", tolower('A'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", toupper('a'));
} */

//// SPLIT MAIN
/* int main(void) 
{
	char		**result;
	const char	*s = "Hello, world! This is a test.";
	char		delimiter = ' ';

	result = ft_split(s, delimiter);

	for (int i = 0; result && result[i]; i++)
	{
		printf("Word %d: %s\n", i + 1, result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
} */

//// MAIN OF STR(R)CHR + SUBSTR + TRIM
/* int main(void)
{
	char *value = "bonjour";
	char *result;

	printf("%s\n", ft_strchr(value, 'o'));
	printf("%s\n", strchr(value, 'o'));
	printf("%s\n", ft_strrchr(value, 'b'));
	printf("%s\n", strrchr(value, 'b'));
	result = ft_substr(value, 1, 3);
	printf("%s\n", result);
	free(result);
	result = ft_strtrim(value, "!Hd");
	printf("%s\n", result);
	free(result);
	printf("%d\n", ft_strncmp("test", "test", 6));
	printf("%d", strncmp("test", "test", 6));
} */

//// MAIN OF STRNSTR + STRMAPI + STRLEN + STRITERI
/* char	ft_to_weird_upper(unsigned int blk, char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}

void	example_function(unsigned int index, char *c)
{
	if ((*c >= 'a' && *c <= 'z'))
		*c = *c - 32;
}

int main(void)
{
	char *value = "Hello World Here comes the woorld";
	char *result;
	char *result2;
	char str[] = "comes the woorld";

	result = ft_strnstr(value, "comes", 22);
	printf("%s\n", result);
	result2 = ft_strmapi(value, ft_to_weird_upper);
	printf("%s\n", result2);
	ft_striteri(str, example_function);
	printf("%s\n", str);
	free(result2);
	printf("%ld\n", ft_strlen("Hello World!"));
	printf("%ld", strlen("Hello World!"));
} */

//// MAIN OF STRDUP + ALL _FD + ITOA + ATOI
/* int	main(void)
{
	char *value = "Hello World!";
	char *cf_value;
	char *ct_value;
	char *a_value;

	cf_value = ft_strdup(value);
	ct_value = strdup(value);

	printf("%s\n%s\n", cf_value, ct_value);
	free(cf_value);
	free(ct_value);

	ft_putchar_fd('c', 1);
	ft_putendl_fd("\nHello World!", 1);
	ft_putstr_fd("Hello World!\n", 1);
	ft_putnbr_fd(-123456, 1);
	a_value = ft_itoa(2147483648);
	printf("\n%s", a_value);
	free(a_value);
	printf("\n%d", ft_atoi("\t\n\r\r\r  -12345"));
	printf("\n%d", atoi("\t\n\r\r\r  -12345"));
} */


//// ALMOST ALL OF MEM...
/* int main()
{
    const char str[] = "Hello, world!";
    size_t n = sizeof(str);

	printf("%s\n", ft_memchr(str, 'w', n));
	printf("%s\n", memchr(str, 'w', n));
	printf("%p\n", ft_memchr(str, 'x', n));
	printf("%p\n", memchr(str, 'x', n));

	printf("%d\n", ft_memcmp("Hello World", "Hello World", 11));
	printf("%d\n", memcmp("Hello World", "Hello World", 11));
	printf("%d\n", ft_memcmp("Helln", "Hello", 6));
	printf("%d\n", memcmp("Helln", "Hello", 6));

	char str1[] = "Hello, world!";
	char str2[] = "Hello, world!";
    ft_memset(str1, 'A', 5);
    memset(str2, 'A', 5);
	printf("%s\n%s\n", str2, str1);

	char str3[20] = "Hello, world!";
    ft_memmove(str3 + 7, str3, 5);
    printf("%s\n", str3);
	strcpy(str3, "Hello, world!");
	memmove(str3 + 7, str3, 5);
    printf("%s\n", str3);
    strcpy(str3, "Hello, world!");
    ft_memmove(str3 + 5, str3, 7);
    printf("%s\n", str3);
	strcpy(str3, "Hello, world!");
	memmove(str3 + 5, str3, 7);
    printf("%s\n", str3);
    return 0;
} */

//// MEMCPY
/* int main()
{
    char source[] = "Hello, world!";
    char destination[20];
	char source2[] = "Hello, world!";
    char destination2[20];

    ft_memcpy(destination, source, 13);
    destination[13] = '\0';
    printf("%s\n", destination);
    memcpy(destination2, source2, 13);
    destination2[13] = '\0';
    printf("%s\n", destination2);

    char smaller_dest[10];
    ft_memcpy(smaller_dest, source, 5);
    smaller_dest[5] = '\0';
    printf("%s\n", smaller_dest);
	char smaller_dest2[10];
    memcpy(smaller_dest2, source, 5);
    smaller_dest2[5] = '\0';
    printf("%s\n", smaller_dest2);

	char str[20] = "Hello, world!";
    ft_bzero(str, 6);
    dprintf(1,"%s\n", str);
	char str2[20] = "Hello, world!";
    bzero(str2, 6);
    dprintf(1,"%s\n", str2);

    return 0;
} */
