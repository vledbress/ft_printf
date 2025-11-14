#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret1, ret2;

	printf("===== TEST %%c =====\n");
	ret1 = printf("printf:  [%c]\n", 'A');
	ret2 = ft_printf("ft_printf:[%c]\n", 'A');
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== TEST %%s =====\n");
	ret1 = printf("printf:  [%s]\n", "Hello");
	ret2 = ft_printf("ft_printf:[%s]\n", "Hello");
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	ret1 = printf("printf:  [%s]\n", NULL);
	ret2 = ft_printf("ft_printf:[%s]\n", NULL);
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== TEST %%p =====\n");
	int x = 42;
	ret1 = printf("printf:  [%p]\n", &x);
	ret2 = ft_printf("ft_printf:[%p]\n", &x);
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== TEST %%d / %%i =====\n");
	ret1 = printf("printf:  [%d] [%i] [%d]\n", 0, -42, 2147483647);
	ret2 = ft_printf("ft_printf:[%d] [%i] [%d]\n", 0, -42, 2147483647);
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== TEST %%u =====\n");
	ret1 = printf("printf:  [%u] [%u]\n", 0, 4294967295u);
	ret2 = ft_printf("ft_printf:[%u] [%u]\n", 0, 4294967295u);
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== TEST %%x / %%X =====\n");
	ret1 = printf("printf:  [%x] [%x] [%X]\n", 0, 305419896, 305419896);
	ret2 = ft_printf("ft_printf:[%x] [%x] [%X]\n", 0, 305419896, 305419896);
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== TEST %%%% =====\n");
	ret1 = printf("printf:  [%%]\n");
	ret2 = ft_printf("ft_printf:[%%]\n");
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	printf("===== MIXED TEST =====\n");
	ret1 = printf("printf:  [%d %u %x %s %c %% %p]\n",
		-123, 999u, 0xabcdef, "test", 'Z', &x);
	ret2 = ft_printf("ft_printf:[%d %u %x %s %c %% %p]\n",
		-123, 999u, 0xabcdef, "test", 'Z', &x);
	printf("ret printf = %d | ret ft = %d\n\n", ret1, ret2);

	return 0;
}
