/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:27:22 by almarico          #+#    #+#             */
/*   Updated: 2023/12/09 16:42:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_w_mid_int(long int integer, t_width *length, t_flag *flag)
{
	size_t			char_counter;

	char_counter = 0;
	if (integer < 0)
	{
		char_counter += write(1, "-", 1);
		integer *= -1;
	}
	if (!(flag->precision == 1 && length->precision == 0 && integer == 0))
	{
		char_counter += ft_write_zero(length->precision, ft_size(integer));
		char_counter += ft_size(integer);
		ft_putnbr_base(integer, TABLEAU_DEC);
	}
	char_counter += ft_write_space(length->width, char_counter);
	return (char_counter);
}

static size_t	ft_write_zero_integer(long int integer, t_width *length)
{
	size_t			char_counter;

	char_counter = 0;
	if (integer < 0)
	{
		char_counter += write(1, "-", 1);
		integer *= -1;
		length->width--;
	}
	char_counter += ft_write_zero(length->width, ft_size(integer));
	char_counter += ft_size(integer);
	ft_putnbr_base(integer, TABLEAU_DEC);
	return (char_counter);
}

static size_t	ft_wnormalint(long int n, t_width *len, t_flag *flag)
{
	size_t			char_counter;

	char_counter = 0;
	if (flag->precision == 1 && len->precision == 0 && n == 0)
		char_counter += ft_write_space(len->width, 0);
	else if (len->precision >= ft_size(n))
		char_counter += ft_write_space(len->width, (len->precision + (n < 0)));
	else
		char_counter += ft_write_space(len->width, ft_size(n));
	if (n < 0)
	{
		char_counter += write(1, "-", 1);
		n *= -1;
	}
	char_counter += ft_write_zero(len->precision, ft_size(n));
	if (!(flag->precision == 1 && len->precision == 0 && n == 0))
	{
		char_counter += ft_size(n);
		ft_putnbr_base(n, TABLEAU_DEC);
	}
	return (char_counter);
}

void	ft_w_integer(int integer, size_t *char_c, t_width *len, t_flag *flag)
{
	if (flag->space == 1 && integer >= 0)
	{
		*char_c += write(1, " ", 1);
		len->width--;
		len->precision--;
	}
	if (flag->plus == 1 && integer >= 0)
	{
		*char_c += write(1, "+", 1);
		len->width--;
		len->precision--;
	}
	if (flag->middlescore == 1)
		*char_c += ft_w_mid_int(integer, len, flag);
	else if (flag->zero == 1)
		*char_c += ft_write_zero_integer(integer, len);
	else
		*char_c += ft_wnormalint(integer, len, flag);
}

void	ft_w_uint(unsigned int integer, size_t *cc, t_width *len, t_flag *f)
{
	if (f->space == 1)
	{
		*cc += write(1, " ", 1);
		len->width--;
		len->precision--;
	}
	if (f->plus == 1)
	{
		*cc += write(1, "+", 1);
		len->width--;
		len->precision--;
	}
	if (f->middlescore == 1)
		*cc += ft_w_mid_int(integer, len, f);
	else if (f->zero == 1)
		*cc += ft_write_zero_integer(integer, len);
	else
		*cc += ft_wnormalint(integer, len, f);
}
