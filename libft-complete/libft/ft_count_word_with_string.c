/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word_with_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:53:57 by almarico          #+#    #+#             */
/*   Updated: 2024/06/18 10:59:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_string(const char c, const char *string_separator)
{
	while (*string_separator != '\0')
	{
		if (c == *string_separator)
			return (1);
		string_separator++;
	}
	return (0);
}

int	ft_count_word_with_string(char const *str, char *string_separator)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (is_in_string(*str, string_separator) == 1 && *str != '\0')
			str++;
		while (is_in_string(*str, string_separator) == 0 && *str != '\0')
			str++;
		count++;
	}
	return (count);
}
