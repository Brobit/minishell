/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:30:50 by almarico          #+#    #+#             */
/*   Updated: 2023/10/29 18:22:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int charactere)
{
	if ((charactere < 'A' || charactere > 'Z')
		&& (charactere < 'a' || charactere > 'z')
		&& (charactere < '0' || charactere > '9'))
		return (0);
	return (charactere);
}
