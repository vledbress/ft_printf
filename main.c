#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	/* ---------- %c ---------- */
	printf("========== %%c TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%c", 'A'));
	printf(" = %d\n\n", printf("%c", 'A'));

	printf(" = %d\n",   ft_printf("%c", 0));
	printf(" = %d\n\n", printf("%c", 0));

	/* ---------- %s ---------- */
	char *s1 = "Hello, world!";
	char *s2 = NULL;
	char *empty = "";
	char *longs = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

	printf("========== %%s TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%s", s1));
	printf(" = %d\n\n", printf("%s", s1));

	printf(" = %d\n",   ft_printf("%s", s2));
	printf(" = %d\n\n", printf("%s", s2));

	printf(" = %d\n",   ft_printf("%s", empty));
	printf(" = %d\n\n", printf("%s", empty));

	printf(" = %d\n",   ft_printf("%s", longs));
	printf(" = %d\n\n", printf("%s", longs));

	/* ---------- %p ---------- */
	int a = 5;

	printf("========== %%p TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%p", &a));
	printf(" = %d\n\n", printf("%p", &a));

	printf(" = %d\n",   ft_printf("%p", NULL));
	printf(" = %d\n\n", printf("%p", NULL));

	/* ---------- %d and %i ---------- */
	int d1 = 0;
	int d2 = -42;
	int d3 = 123456789;
	long long d4 = -2147483648LL;

	printf("========== %%d / %%i TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%d", d1));
	printf(" = %d\n\n", printf("%d", d1));

	printf(" = %d\n",   ft_printf("%d", d2));
	printf(" = %d\n\n", printf("%d", d2));

	printf(" = %d\n",   ft_printf("%d", d3));
	printf(" = %d\n\n", printf("%d", d3));

	printf(" = %d\n",   ft_printf("%d", d4));
	printf(" = %d\n\n", printf("%d", d4));

	printf(" = %d\n",   ft_printf("%i", d2));
	printf(" = %d\n\n", printf("%i", d2));

	printf(" = %d\n",   ft_printf("%i", d4));
	printf(" = %d\n\n", printf("%i", d4));

	/* ---------- %u ---------- */
	unsigned int u1 = 0;
	unsigned int u2 = 42;
	unsigned int u3 = 4294967295u;

	printf("========== %%u TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%u", u1));
	printf(" = %d\n\n", printf("%u", u1));

	printf(" = %d\n",   ft_printf("%u", u2));
	printf(" = %d\n\n", printf("%u", u2));

	printf(" = %d\n",   ft_printf("%u", u3));
	printf(" = %d\n\n", printf("%u", u3));

	/* ---------- %x and %X ---------- */
	unsigned int hx1 = 0;
	unsigned int hx2 = 305419896;  // 0x12345678
	unsigned int hx3 = 4294967295u;

	printf("========== %%x / %%X TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%x", hx1));
	printf(" = %d\n\n", printf("%x", hx1));

	printf(" = %d\n",   ft_printf("%x", hx2));
	printf(" = %d\n\n", printf("%x", hx2));

	printf(" = %d\n",   ft_printf("%x", hx3));
	printf(" = %d\n\n", printf("%x", hx3));

	printf(" = %d\n",   ft_printf("%X", hx2));
	printf(" = %d\n\n", printf("%X", hx2));

	/* ---------- %% ---------- */
	printf("========== %%%% TESTS ==========\n");
	printf(" = %d\n",   ft_printf("%%"));
	printf(" = %d\n\n", printf("%%"));

	printf(" = %d\n",   ft_printf("%%%%"));
	printf(" = %d\n\n", printf("%%%%"));

	return 0;
}
