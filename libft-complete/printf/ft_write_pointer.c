/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:14:55 by almarico          #+#    #+#             */
/*   Updated: 2023/12/06 12:54:14 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_hex_addr(uintptr_t addr, size_t *char_counter)
{
	if (addr != 0)
		ft_write_hex_addr(addr / 16, char_counter);
	if (addr != 0)
		*char_counter += write(1, &TABLEAU_LOW_HEX[addr % 16], 1);
}

size_t	ft_size_addr(uintptr_t addr)
{
	size_t	size_counter;

	size_counter = 0;
	if (addr == 0)
		size_counter++;
	while (addr != 0)
	{
		addr /= 16;
		size_counter++;
	}
	return (size_counter);
}

static void	ft_wmid_pointer(uintptr_t p, size_t *char_c, t_width *len)
{
	if (p == 0)
	{
		*char_c += write(1, "(nil)", 5);
		*char_c += ft_write_space(len->width, 5);
	}
	else
	{
		len->width -= 2;
		*char_c += write(1, "0x", 2);
		ft_write_hex_addr(p, char_c);
		*char_c += ft_write_space(len->width, ft_size_addr(p));
	}
}

static void	ft_wnormal_pointer(uintptr_t p, size_t *char_c, t_width *len)
{
	if (p == 0)
	{
		*char_c += ft_write_space(len->width, 5);
		*char_c += write(1, "(nil)", 5);
	}
	else
	{
		len->width -= 2;
		*char_c += ft_write_space(len->width, ft_size_addr(p));
		*char_c += write(1, "0x", 2);
		ft_write_hex_addr(p, char_c);
	}
}

void	ft_w_pointer(uintptr_t p, size_t *char_c, t_flag *flag, t_width *len)
{
	if (flag->middlescore == 1)
		ft_wmid_pointer(p, char_c, len);
	else
		ft_wnormal_pointer(p, char_c, len);
}
