/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:53:57 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/16 16:05:26 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_numbers.h"
#include "ft_printf_strings.h"

static int	ft_print_variadic(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'x')
		return (ft_putnbr_base_unsigned(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (spec == 'X')
		return (ft_putnbr_base_unsigned(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (spec == 'u')
		return (ft_putnbr_base_unsigned(va_arg(args, unsigned int),
				"0123456789"));
	else if (spec == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		symbols;

	if (!format)
		return (-1);
	symbols = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			symbols += ft_print_variadic(*format, args);
		}
		else if (*format != '%')
			symbols += ft_putchar(*format);
		else
			break ;
		format++;
	}
	va_end(args);
	return (symbols);
}
