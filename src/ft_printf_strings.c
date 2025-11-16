/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:04:45 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/16 15:05:39 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_strings.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}
