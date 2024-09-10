/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:40:08 by almarico          #+#    #+#             */
/*   Updated: 2024/01/10 12:42:32 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != c && *str != '\0')
			str++;
		while (*str == c && *str != '\0')
			str++;
		count++;
	}
	return (count);
}
