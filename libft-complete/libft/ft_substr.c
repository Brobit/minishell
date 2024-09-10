/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:52:54 by almarico          #+#    #+#             */
/*   Updated: 2024/03/03 12:07:43 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
	{
		free(tab);
		tab = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	return (tab);
}
