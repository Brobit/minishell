/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:28:53 by almarico          #+#    #+#             */
/*   Updated: 2023/12/03 13:20:38 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(char *base, long nbr, int base_len)
{
	if (nbr >= base_len)
		ft_write(base, nbr / base_len, base_len);
	write(1, &base[nbr % base_len], 1);
}

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (1);
	while (base[i])
	{
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

void	ft_putnbr_base(long int nbr, char *base)
{
	int		base_len;

	if (ft_check_base(base) != 1)
	{
		base_len = ft_strlen(base);
		if (nbr < 0)
		{
			write (1, "-", 1);
			nbr *= -1;
		}
		ft_write(base, nbr, base_len);
	}
}
