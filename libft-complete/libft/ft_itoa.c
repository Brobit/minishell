/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:31:48 by almarico          #+#    #+#             */
/*   Updated: 2023/12/03 12:12:26 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long long int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		n *= -1;
		size++;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	long	tmp;
	char	*res;

	tmp = n;
	size = ft_size(tmp);
	res = ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (tmp < 0)
	{
		tmp *= -1;
		res[0] = '-';
	}
	--size;
	while (size >= (n < 0))
	{
		res[size--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (res);
}
