/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:53:33 by almarico          #+#    #+#             */
/*   Updated: 2024/03/05 21:06:08 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ll	ft_atoll(const char *string)
{
	t_ll	neg;
	t_ll	res;
	int		i;

	res = 0;
	i = 0;
	neg = 1;
	while ((string[i] >= '\t' && string[i] <= '\r') || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			neg *= -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		res *= 10;
		res += (string[i] - '0');
		i++;
		if (res > INT_MAX || res < INT_MIN)
			return (res * neg);
	}
	return (res * neg);
}
