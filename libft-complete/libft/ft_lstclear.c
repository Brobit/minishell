/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:43:08 by almarico          #+#    #+#             */
/*   Updated: 2024/02/14 12:08:57 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nav;

	while (*lst)
	{
		nav = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nav;
	}
	free(*lst);
	*lst = NULL;
}
