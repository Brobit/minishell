/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:44:50 by almarico          #+#    #+#             */
/*   Updated: 2024/10/21 13:50:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	free_redirection_list(t_redirection **list)
{
	t_redirection	*nav;

	while (*list)
	{
		nav = (*list)->next;
		free((void *)(*list)->payload);
		free((*list));
		*list = nav;
	}
	free(*list);
	*list = NULL;
}

void	free_exec_list(t_exec **exec)
{
	t_exec	*nav;
	int		i;

	while (*exec)
	{
		nav = (*exec)->next;
		free_redirection_list(&(*exec)->redirection_list);
		free((*exec)->cmd);
		(*exec)->cmd = NULL;
		i = 0;
		if ((*exec)->option)
			while ((*exec)->option[i])
				free((*exec)->option[i++]);
		free((*exec)->option);
		(*exec)->option = NULL;
		free(*exec);
		*exec = nav;
	}
	free(*exec);
	*exec = NULL;
}
