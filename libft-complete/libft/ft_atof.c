/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:30:20 by almarico          #+#    #+#             */
/*   Updated: 2024/06/16 18:49:38 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	decimal(const char **string, float *res)
{
	while (ft_isdigit(**string))
	{
		*res *= 10;
		*res += **string - '0';
		(*string)++;
	}
}

static void	fraction(const char **string, float *res)
{
	float	divide;

	divide = 10;
	while (ft_isdigit(**string))
	{
		*res = (**string - '0') / divide;
		divide *= 10;
		(*string)++;
	}
}

float	ft_atof(const char *string)
{
	float	res;
	float	neg;

	res = 0;
	neg = 1;
	while (ft_isspace(*string) == 0)
		string++;
	if (*string == '+' || *string == '-')
	{
		if (*string == '-')
			neg *= -1;
		string++;
	}
	decimal(&string, &res);
	if (*string == ',' || *string == '.')
		fraction(&string, &res);
	return (res * neg);
}
