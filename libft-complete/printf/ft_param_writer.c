/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_writer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:01:41 by almarico          #+#    #+#             */
/*   Updated: 2023/12/06 13:29:04 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_param(va_list ap, t_specifier *the, t_flag *f, t_width *len)
{
	size_t	char_counter;

	char_counter = 0;
	if (the->specifier == '%')
		ft_write_char('%', &char_counter, f, len);
	else if (the->specifier == 'c')
		ft_write_char(va_arg(ap, int), &char_counter, f, len);
	else if (the->specifier == 's')
		ft_write_str(va_arg(ap, char *), &char_counter, f, len);
	else if (the->specifier == 'p')
		ft_w_pointer(va_arg(ap, uintptr_t), &char_counter, f, len);
	else if (the->specifier == 'd' || the->specifier == 'i')
		ft_w_integer(va_arg(ap, int), &char_counter, len, f);
	else if (the->specifier == 'u')
		ft_w_uint(va_arg(ap, unsigned int), &char_counter, len, f);
	else if (the->specifier == 'x' || the->specifier == 'X')
		char_counter += ft_w_hex(va_arg(ap, unsigned int), the, f, len);
	return (char_counter);
}
