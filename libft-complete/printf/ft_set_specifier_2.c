/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_specifier_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:04:53 by almarico          #+#    #+#             */
/*   Updated: 2023/11/30 18:10:16 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_specifier_i(t_flag *flag)
{
	flag->diese = 0;
	if (flag->middlescore == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->plus == 1 && flag->space == 1)
		flag->space = 0;
	if (flag->zero == 1 && flag->precision == 1)
		flag->zero = 0;
}

void	ft_set_specifier_u(t_flag *flag)
{
	flag->diese = 0;
	flag->plus = 0;
	if (flag->middlescore == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->zero == 1 && flag->precision == 1)
		flag->zero = 0;
}

void	ft_set_specifier_x(t_flag *flag)
{
	flag->plus = 0;
	flag->space = 0;
	if (flag->middlescore == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->zero == 1 && flag->precision == 1)
		flag->zero = 0;
}

void	ft_set_specifier_uppx(t_flag *flag)
{
	flag->plus = 0;
	flag->space = 0;
	if (flag->middlescore == 1 && flag->zero == 1)
		flag->zero = 0;
	if (flag->zero == 1 && flag->precision == 1)
		flag->zero = 0;
}
