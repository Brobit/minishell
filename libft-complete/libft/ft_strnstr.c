/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:24:58 by almarico          #+#    #+#             */
/*   Updated: 2023/10/29 18:39:31 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	int		i;
	int		j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (len > 0 && big[i])
	{
		count = len;
		j = 0;
		if (big[i] == little[j])
		{
			while (count-- > 0 && (big[i + j] == little[j]) && little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
