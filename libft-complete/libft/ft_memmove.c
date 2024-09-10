/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:35:08 by almarico          #+#    #+#             */
/*   Updated: 2023/10/21 20:36:24 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	c_dest = (char *)dest;
	c_src = (char *)src;
	i = -1;
	if (c_dest > c_src)
		while (n-- > 0)
			c_dest[n] = c_src[n];
	else
	{
		while (++i < n)
			c_dest[i] = c_src[i];
	}
	return (dest);
}
