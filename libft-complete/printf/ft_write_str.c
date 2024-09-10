/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:07 by almarico          #+#    #+#             */
/*   Updated: 2023/12/16 15:19:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wnormalstr(char *str, size_t *char_c, t_flag *flag, t_width *len)
{
	ssize_t	size;

	size = 0;
	if (flag->middlescore == 0)
	{
		*char_c += ft_write_space(len->width, len->precision);
		while (len->precision > 0 && *str)
		{
			*char_c += write(1, str++, 1);
			len->precision--;
		}
	}
	if (flag->middlescore == 1)
	{
		size = len->precision;
		while (len->precision > 0 && *str)
		{
			*char_c += write(1, str++, 1);
			len->precision--;
		}
		*char_c += ft_write_space(len->width, size);
	}
}

static void	ft_write_nstr(size_t *char_c, t_flag *flag, t_width *len)
{
	if (flag->middlescore == 0)
	{
		*char_c += ft_write_space(len->width, len->precision);
		if (len->precision == 6)
			*char_c += write(1, "(null)", len->precision);
	}
	if (flag->middlescore == 1)
	{
		if (len->precision == 6)
			*char_c += write(1, "(null)", len->precision);
		*char_c += ft_write_space(len->width, len->precision);
	}
}

static void	ft_set_len(char *str, t_flag *flag, t_width *length)
{
	if (flag->precision == 0 && str)
		length->precision = ft_strlen(str);
	if ((size_t)length->precision > ft_strlen(str) && str)
		length->precision = ft_strlen(str);
	else if (!str && length->precision > 6)
		length->precision = 6;
	else if (!str && length->precision < 6 && flag->precision == 1)
		length->precision = 0;
	else if (!str && flag->precision == 0)
		length->precision = 6;
}

void	ft_write_str(char *str, size_t *char_c, t_flag *flag, t_width *length)
{
	ft_set_len(str, flag, length);
	if (str == NULL)
		ft_write_nstr(char_c, flag, length);
	else
		ft_wnormalstr(str, char_c, flag, length);
}
