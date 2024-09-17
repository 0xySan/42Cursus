#ifndef LIBFT_H
# define LIBFT_H
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_next_line(int fd);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif