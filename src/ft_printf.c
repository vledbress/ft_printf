/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:53:57 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/15 21:58:45 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	len;
	
	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_putnbr(int num)
{
	long long int	n;
	int				symbols;

	n = num;
	symbols = 0;
	if (n < 0)
	{
		symbols += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		symbols += ft_putnbr(n / 10);
	symbols += ft_putchar((n % 10) + '0');
	return (symbols);
}

static int	ft_putnbr_base_unsigned(unsigned long long num, char *base)
{
    size_t base_len;
	int		symbols;

	symbols = 0;
	base_len = ft_strlen(base);
    if (num >= base_len)
        symbols += ft_putnbr_base_unsigned(num / base_len, base);
    symbols += ft_putchar(base[num % base_len]);
	return (symbols);
}

//TODO: make this function return n printed symbols
static int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	int				symbols;
	
	symbols = 0;
	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	address = (unsigned long)ptr;
	symbols += ft_putstr("0x");
	symbols += ft_putnbr_base_unsigned(address, "0123456789abcdef");
	return (symbols);
}

//TODO: make this function return n printed symbols
int ft_printf(const char *format, ...)
{
	va_list args;
	char	letter;
	int		symbols;
	
	if (!format)
		return (-1);
	symbols = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			letter = *(++format);
			if (letter == 'c')
				symbols +=ft_putchar((char)va_arg(args, int));
			else if (letter == 's')
				symbols +=ft_putstr(va_arg(args, char *));
			else if (letter == 'd' || letter == 'i')
				symbols +=ft_putnbr(va_arg(args, int));
			else if (letter == 'x')
				symbols +=ft_putnbr_base_unsigned(va_arg(args, unsigned int),  "0123456789abcdef");
			else if (letter == 'X')
				symbols +=ft_putnbr_base_unsigned(va_arg(args, unsigned int),  "0123456789ABCDEF");
			else if (letter == 'u')
				symbols +=ft_putnbr_base_unsigned(va_arg(args, unsigned int),  "0123456789");
			else if (letter == 'p')
				symbols +=ft_print_pointer(va_arg(args, void *));
			else if (letter == '%')
				symbols +=ft_putchar('%');
		}
		else 
			symbols += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (symbols);
}



