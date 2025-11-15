/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:18:21 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/15 22:18:22 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdlib.h> //malloc, free
#include <unistd.h> //write
#include <stdarg.h> //va_start, va_arg, va_copy, va_end



int ft_printf(const char *, ...);


# endif