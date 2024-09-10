/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:47:39 by almarico          #+#    #+#             */
/*   Updated: 2024/02/14 12:09:51 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*pilou;

	pilou = malloc(sizeof(t_list));
	if (!pilou)
		return (NULL);
	pilou->content = content;
	pilou->next = NULL;
	return (pilou);
}
