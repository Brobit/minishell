/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:38:12 by almarico          #+#    #+#             */
/*   Updated: 2023/12/16 15:19:47 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list				ap;
	size_t				char_counter;
	t_flag				flag;
	t_width				length;
	t_specifier			the;

	va_start(ap, str);
	char_counter = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_init(&flag, &length, &the);
			ft_chparam(&str, &length, &the, &flag);
			ft_check_conflict(&the, &length, &flag);
			char_counter += ft_write_param(ap, &the, &flag, &length);
		}
		if (*str != '\0' && *str != '%')
			char_counter += write(1, (const void *)str++, 1);
	}
	va_end(ap);
	return (char_counter);
}
