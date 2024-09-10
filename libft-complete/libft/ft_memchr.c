/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:30:43 by almarico          #+#    #+#             */
/*   Updated: 2023/12/01 13:30:50 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;

	i = 0;
	while (n > 1 && ((char *)s)[i] != (char)c)
	{
		n--;
		i++;
	}
	if (((char *)s)[i] == (char)c && n)
		return ((void *)(s + i));
	return (NULL);
}
