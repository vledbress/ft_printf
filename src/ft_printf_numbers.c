/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:24:06 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/16 15:06:35 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_strings.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putnbr(int num)
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

int	ft_putnbr_base_unsigned(unsigned long long num, char	*base)
{
	size_t	base_len;
	int		symbols;

	symbols = 0;
	base_len = ft_strlen(base);
	if (num >= base_len)
		symbols += ft_putnbr_base_unsigned(num / base_len, base);
	symbols += ft_putchar(base[num % base_len]);
	return (symbols);
}

int	ft_print_pointer(void *ptr)
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
