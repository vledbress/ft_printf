#include <stdio.h>
#include "ft_printf.h"

// int main(void)
// {
//     int     r1, r2;
//     char    c = 'A';
//     char    *s = "Hello, world!";
//     char    *nulls = NULL;
//     int     d = -12345;
//     int     i = 6789;
//     unsigned int u = 4294967295U;   // max unsigned
//     unsigned int x = 0xabcdef;
//     void    *p = (void*)0x1234abcd;

//     printf("==== TEST %%c ====\n");
//     r1 = printf("printf: [%c]\n", c);
//     r2 = ft_printf("ft_printf: [%c]\n", c);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%s ====\n");
//     r1 = printf("printf: [%s] [%s]\n", s, nulls);
//     r2 = ft_printf("ft_printf: [%s] [%s]\n", s, nulls);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%p ====\n");
//     r1 = printf("printf: [%p]\n", p);
//     r2 = ft_printf("ft_printf: [%p]\n", p);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%d ====\n");
//     r1 = printf("printf: [%d] [%d]\n", d, 0);
//     r2 = ft_printf("ft_printf: [%d] [%d]\n", d, 0);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%i ====\n");
//     r1 = printf("printf: [%i] [%i]\n", i, -1);
//     r2 = ft_printf("ft_printf: [%i] [%i]\n", i, -1);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%u ====\n");
//     r1 = printf("printf: [%u] [%u]\n", u, 0);
//     r2 = ft_printf("ft_printf: [%u] [%u]\n", u, 0);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%x ====\n");
//     r1 = printf("printf: [%x] [%x]\n", x, 0);
//     r2 = ft_printf("ft_printf: [%x] [%x]\n", x, 0);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%X ====\n");
//     r1 = printf("printf: [%X] [%X]\n", x, 0);
//     r2 = ft_printf("ft_printf: [%X] [%X]\n", x, 0);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== TEST %%%% ====\n");
//     r1 = printf("printf: [%%]\n");
//     r2 = ft_printf("ft_printf: [%%]\n");
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     printf("==== COMBINED TEST ====\n");
//     r1 = printf("printf: %c %s %p %d %i %u %x %X %%\n",
//                 c, s, p, d, i, u, x, x);
//     r2 = ft_printf("ft_printf: %c %s %p %d %i %u %x %X %%\n",
//                    c, s, p, d, i, u, x, x);
//     printf("ret printf = %d | ret ft_printf = %d\n\n", r1, r2);

//     return 0;
// }


int main()
{
	ft_printf("%%\n");
	printf("%%\n");
}