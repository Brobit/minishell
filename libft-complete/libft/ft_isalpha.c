/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:41:23 by almarico          #+#    #+#             */
/*   Updated: 2023/10/29 18:22:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int charactere)
{
	if ((charactere < 'A' || charactere > 'Z')
		&& (charactere < 'a' || charactere > 'z'))
		return (0);
	return (charactere);
}
