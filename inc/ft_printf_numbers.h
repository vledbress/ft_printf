/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:09:08 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/16 15:07:35 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_NUMBERS_H
# define FT_PRINTF_NUMBERS_H

# include <stdlib.h>

int	ft_putnbr(int num);

int	ft_putnbr_base_unsigned(unsigned long long num, char *base);

int	ft_print_pointer(void *ptr);

#endif