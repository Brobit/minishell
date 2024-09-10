/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:19:09 by almarico          #+#    #+#             */
/*   Updated: 2023/12/02 14:16:20 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flag *flag, t_width *length, t_specifier *the)
{
	ft_bzero(flag, sizeof(t_flag));
	ft_bzero(length, sizeof(t_width));
	ft_bzero(the, sizeof(t_specifier));
}
