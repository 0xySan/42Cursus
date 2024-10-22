#include "ft_printf.h"

int main()
{
	char *test = "Hello";
	printf("%d\n\n", ft_printf("%%%%\n%c\n%s\n%d\n%i\n%x\n%X\n%u\n%p\n", 'a', "n", 0, 0, 0, 0, 123, test));
	printf("%d\n", printf("%%%%\n%c\n%s\n%d\n%i\n%x\n%X\n%u\n%p\n", 'a', "n", 0, 0, 0, 0, 123, test));
	return 0;
}
