/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:38:28 by almarico          #+#    #+#             */
/*   Updated: 2024/10/17 15:39:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

t_redirection	*redirection_list_new_node(void)
{
	t_redirection	*new;

	new = malloc(sizeof(t_exec));
	if (!new)
		return (NULL);
	new->type = NONE;
	new->payload = NULL;
	new->next = NULL;
	return (new);
}

t_redirection	*redirection_list_last(t_redirection *lst)
{
	t_redirection	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	redirection_list_add_back(t_redirection **exec, t_redirection *neww)
{
	t_redirection	*last;

	last = redirection_list_last(*exec);
	if (last)
		last->next = neww;
	else
		*exec = neww;
}
