/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:02:54 by almarico          #+#    #+#             */
/*   Updated: 2023/10/29 18:28:01 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*tab;
	unsigned int		i;

	i = -1;
	tab = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s[++i])
		tab[i] = (*f)(i, s[i]);
	tab[i] = '\0';
	return (tab);
}
