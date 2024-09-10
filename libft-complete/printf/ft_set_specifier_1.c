/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_specifier_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:08 by almarico          #+#    #+#             */
/*   Updated: 2023/12/04 11:44:03 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_specifier_c(t_flag *flag, t_width *length)
{
	flag->plus = 0;
	flag->zero = 0;
	flag->diese = 0;
	flag->space = 0;
	flag->precision = 0;
	length->precision = 0;
}

void	ft_set_specifier_s(t_flag *flag)
{
	flag->plus = 0;
	flag->zero = 0;
	flag->diese = 0;
	flag->space = 0;
}

void	ft_set_specifier_p(t_flag *flag, t_width *length)
{
	flag->plus = 0;
	flag->zero = 0;
	flag->diese = 0;
	flag->space = 0;
	flag->precision = 0;
	length->precision = 0;
}

void	ft_set_specifier_d(t_flag *flag)
{
	flag->diese = 0;
	if (flag->middlescore == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->plus == 1 && flag->space == 1)
		flag->space = 0;
	if (flag->zero == 1 && flag->precision == 1)
		flag->zero = 0;
}

void	ft_set_specifier_modulo(t_flag *flag, t_width *length)
{
	flag->middlescore = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->diese = 0;
	flag->precision = 0;
	length->precision = 0;
	length->width = 0;
}
