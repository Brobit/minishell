/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:54:13 by almarico          #+#    #+#             */
/*   Updated: 2023/12/06 13:06:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(int c, size_t *char_counter, t_flag *flag, t_width *len)
{
	if (flag->middlescore == 1)
	{
		write(1, &c, 1);
		*char_counter += ft_write_space(len->width, 1);
	}
	else
	{
		*char_counter += ft_write_space(len->width, 1);
		write(1, &c, 1);
	}
	(*char_counter)++;
}
