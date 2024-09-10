/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:44:18 by almarico          #+#    #+#             */
/*   Updated: 2023/12/16 15:20:24 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_wmhex(unsigned int n, t_width *len,
						t_specifier *the, t_flag *flag)
{
	size_t	cc;

	cc = 0;
	if (!(flag->precision == 1 && len->precision == 0 && n == 0))
	{
		cc += ft_write_zero(len->precision, ft_size_addr(n));
		if (the->specifier == 'x')
			ft_putnbr_base_hex(n, TABLEAU_LOW_HEX, &cc);
		if (the->specifier == 'X')
			ft_putnbr_base_hex(n, TABLEAU_UPP_HEX, &cc);
	}
	cc += ft_write_space(len->width, cc);
	return (cc);
}

static void	ft_wzhex(unsigned int n, t_width *len, t_specifier *the, size_t *cc)
{
	*cc += ft_write_zero(len->width, ft_size_addr(n));
	if (the->specifier == 'x')
		ft_putnbr_base_hex(n, TABLEAU_LOW_HEX, cc);
	if (the->specifier == 'X')
		ft_putnbr_base_hex(n, TABLEAU_UPP_HEX, cc);
}

static size_t	ft_wnhex(unsigned int n, t_width *len,
						t_specifier *the, t_flag *flag)
{
	size_t	cc;

	cc = 0;
	if (flag->precision == 1 && len->precision == 0 && n == 0)
		cc += ft_write_space(len->width, 0);
	else if (flag->precision == 1 && ((size_t)len->precision > ft_size_addr(n)))
		cc += ft_write_space(len->width, len->precision);
	else
		cc += ft_write_space(len->width, ft_size_addr(n));
	cc += ft_write_zero(len->precision, ft_size_addr(n));
	if (!(flag->precision == 1 && len->precision == 0 && n == 0))
	{
		if (the->specifier == 'x')
			ft_putnbr_base_hex(n, TABLEAU_LOW_HEX, &cc);
		if (the->specifier == 'X')
			ft_putnbr_base_hex(n, TABLEAU_UPP_HEX, &cc);
	}
	return (cc);
}

size_t	ft_w_hex(unsigned int n, t_specifier *the, t_flag *flag, t_width *len)
{
	size_t	char_counter;

	char_counter = 0;
	if (flag->diese == 1 && the->specifier == 'x' && n != 0)
	{
		char_counter += write(1, "0x", 2);
		len->width--;
		len->precision--;
	}
	else if (flag->diese == 1 && the->specifier == 'X' && n != 0)
	{
		char_counter += write(1, "0X", 2);
		len->width--;
		len->precision--;
	}
	if (flag->middlescore == 1)
		char_counter += ft_wmhex(n, len, the, flag);
	else if (flag->zero == 1)
		ft_wzhex(n, len, the, &char_counter);
	else
		char_counter += ft_wnhex(n, len, the, flag);
	return (char_counter);
}
