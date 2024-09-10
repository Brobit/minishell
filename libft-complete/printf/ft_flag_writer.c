/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_writer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:26 by almarico          #+#    #+#             */
/*   Updated: 2023/12/03 12:52:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_space(int len, int stopper)
{
	size_t	char_counter;

	char_counter = 0;
	while (len-- > stopper)
		char_counter += write(1, " ", 1);
	return (char_counter);
}

size_t	ft_write_zero(int len, int stopper)
{
	size_t	char_counter;

	char_counter = 0;
	while (len-- > stopper)
		char_counter += write(1, "0", 1);
	return (char_counter);
}
