/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:08:24 by almarico          #+#    #+#             */
/*   Updated: 2023/10/27 19:25:22 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nombre;
	char	c;

	nombre = n;
	if (nombre < 0)
	{
		write(fd, "-", 1);
		nombre *= -1;
	}
	if (nombre < 10)
	{
		c = nombre + '0';
		write(fd, &c, 1);
	}
	if (nombre >= 10)
	{
		ft_putnbr_fd(nombre / 10, fd);
		c = (nombre % 10) + '0';
		write(fd, &c, 1);
	}
}
