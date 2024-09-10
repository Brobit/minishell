/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conflit_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:52:37 by almarico          #+#    #+#             */
/*   Updated: 2023/12/04 11:44:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_conflict(t_specifier *the, t_width *length, t_flag *flag)
{
	if (the->specifier == 'c')
		ft_set_specifier_c(flag, length);
	else if (the->specifier == 's')
		ft_set_specifier_s(flag);
	else if (the->specifier == 'p')
		ft_set_specifier_p(flag, length);
	else if (the->specifier == 'd')
		ft_set_specifier_d(flag);
	else if (the->specifier == 'i')
		ft_set_specifier_i(flag);
	else if (the->specifier == 'u')
		ft_set_specifier_u(flag);
	else if (the->specifier == 'x')
		ft_set_specifier_x(flag);
	else if (the->specifier == 'X')
		ft_set_specifier_uppx(flag);
	else if (the->specifier == '%')
		ft_set_specifier_modulo(flag, length);
}
