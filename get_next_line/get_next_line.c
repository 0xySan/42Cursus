
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


void    ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
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

char *get_next_line(int fd)
{
    char *buff;
    static char *leftover = 0;
    size_t len;
    char *temp;
    char *temp2;
    int ret;

    if (!leftover)
    {
        leftover = malloc(1);
        leftover[0] = 0;
    }

    if ((temp = ft_strchr(leftover, '\n')) != 0)
    {
        len = temp - leftover + 1;
        temp2 = ft_substr(leftover, 0, len);
        temp = ft_substr(leftover, len, ft_strlen(leftover) - len);
        free(leftover);
        leftover = temp;
        return temp2;
    }

    ret = BUFFER_SIZE;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while (ft_strchr(leftover, '\n') == 0 && ret == BUFFER_SIZE)
    {
        ft_bzero(buff, BUFFER_SIZE + 1);
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret <= 0)
        {
            if (ft_strlen(leftover) > 0)
            {
                temp2 = ft_strdup(leftover);
                free(leftover);
                leftover = NULL;
                return temp2;
            }
            return NULL;
        }
        temp = ft_strjoin(leftover, buff);
        free(leftover);
        leftover = temp;
    }

    free(buff);

    if ((temp = ft_strchr(leftover, '\n')) != 0)
    {
        len = temp - leftover + 1;
        temp2 = ft_substr(leftover, 0, len);
        temp = ft_substr(leftover, len, ft_strlen(leftover) - len);
        free(leftover);
        leftover = temp;
        return temp2;
    }

    if (ret == 0 && ft_strlen(leftover) > 0)
    {
        temp2 = ft_strdup(leftover);
        free(leftover);
        leftover = NULL;
        return temp2;
    }

    return NULL;
}



int main(int argc, char **argv)
{
    (void)argc;
	int fd = open(argv[1], O_RDONLY);
	char *temp;
	while((temp = get_next_line(fd)))
		dprintf(1, "%s", temp);
}



// test
