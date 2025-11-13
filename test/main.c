#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	ft_printf("%s -> %i -> %d\n", "ilka pidor", INT_MAX, INT_MIN);



	ft_printf("%X\n", 48879);
	printf("%X\n\n", 48879);

	ft_printf("%x\n", 48879);
	printf("%x\n", 48879);


	int *n = malloc(1);
	printf("%p\n", n);

	free(n);
}


