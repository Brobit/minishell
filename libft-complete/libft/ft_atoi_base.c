/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:32:55 by almarico          #+#    #+#             */
/*   Updated: 2024/08/20 11:56:59 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (1);
	while (base[i])
	{
		if ((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			return (1);
		if (base[i] == '+' || base [i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_is_in_base(char c, char *base)
{
	int	j;

	j = 0;
	while (c != base[j])
		j++;
	if (c == base[j])
		return (0);
	return (1);
}

static unsigned int	ft_cstr(char c, char *base)
{
	unsigned int	j;

	j = 0;
	while (c != base[j])
		j++;
	return (j);
}

static int	check_res(long number)
{
	int	res;

	res = 0;
	if (number < INT_MIN)
		res = INT_MIN;
	else if (number > INT_MAX)
		res = INT_MAX;
	else
		res = number;
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int		res;
	long	neg;
	int		i;

	i = 0;
	res = 0;
	neg = 1;
	if (ft_check_base(base) == 1)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && ft_is_in_base(str[i], base) == 0)
	{
		res *= ft_strlen(base);
		res += ft_cstr(str[i], base);
		i++;
	}
	return (check_res(res * neg));
}
