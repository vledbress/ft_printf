/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:53:57 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/13 23:04:56 by vborysov         ###   ########.fr       */
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

static void	ft_putnbr(int num)
{
	long long int	dummy;

	dummy = num;
	if (num < 0)
	{
		ft_putchar('-');
		dummy = -dummy;
	}
	if (dummy >= 10)
		ft_putnbr(dummy / 10);
	ft_putchar((dummy % 10) + '0');
}


static void ft_putnbr_base_unsigned(unsigned long long num, char *base)
{
    size_t base_len;

	base_len = ft_strlen(base);
    if (num >= base_len)
        ft_putnbr_base_unsigned(num / base_len, base);
    ft_putchar(base[num % base_len]);
}

static void	ft_print_pointer(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	ft_putstr("0x");
	ft_putnbr_base_unsigned(address, "0123456789abcdef");
}

int ft_printf(const char *format, ...)
{
	va_list args;
	char	letter;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			letter = *(++format);
			if (letter == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (letter == 's')
				ft_putstr(va_arg(args, char *));
			else if (letter == 'd' || letter == 'i')
				ft_putnbr(va_arg(args, int));
			else if (letter == 'x')
				ft_putnbr_base_unsigned(va_arg(args, unsigned int),  "0123456789abcdef");
			else if (letter == 'X')
				ft_putnbr_base_unsigned(va_arg(args, unsigned int),  "0123456789ABCDEF");
			else if (letter == 'u')
				ft_putnbr_base_unsigned(va_arg(args, unsigned int),  "0123456789");
			else if (letter == 'p')
				ft_print_pointer(va_arg(args, void *));
			else if (letter == '%')
				ft_putchar('%');
		}
		else 
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (0);
}



