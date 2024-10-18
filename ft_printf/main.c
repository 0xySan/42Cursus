#include "libprintf.h"

int main()
{
	char *test = "Hello";
	ft_printf("%%%%\n%c\n%s\n%d\n%i\n%x\n%X\n%u\n%p\n", 0, "n", 0, 0, 0, 0, 123, test);
	printf("%%%%\n%c\n%s\n%d\n%i\n%x\n%X\n%u\n%p\n", 0, "n", 0, 0, 0, 0, 123, test);
	return 0;
}
