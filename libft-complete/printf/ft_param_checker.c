/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:46:42 by almarico          #+#    #+#             */
/*   Updated: 2023/12/16 15:17:46 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flag(char c)
{
	if (c == '-' || c == ' ' || c == '0' || c == '+' || c == '#')
		return (1);
	return (0);
}

static int	ft_check_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

static void	ft_flag_initializer(char c, t_flag *flag)
{
	if (c == '-')
		flag->middlescore = 1;
	else if (c == ' ')
		flag->space = 1;
	else if (c == '0')
		flag->zero = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '#')
		flag->diese = 1;
	else if (c == '.')
		flag->precision = 1;
}

void	ft_chparam(const char **s, t_width *len, t_specifier *the, t_flag *f)
{
	while (ft_check_flag(**s))
	{
		ft_flag_initializer(**s, f);
		(*s)++;
	}
	if (ft_isdigit(**s))
	{
		len->width = ft_atoi(*s);
		(*s) += ft_size(len->width);
	}
	if (ft_check_precision(**s))
	{
		ft_flag_initializer(**s, f);
		(*s)++;
	}
	if (ft_isdigit(**s))
	{
		while (**s == '0')
			(*s)++;
		len->precision = ft_atoi(*s);
		if (len->precision != 0)
			(*s) += ft_size(len->precision);
	}
	the->specifier = **s;
	(*s)++;
}
