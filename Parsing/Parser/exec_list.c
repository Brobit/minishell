/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:23:38 by almarico          #+#    #+#             */
/*   Updated: 2024/10/18 14:26:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

t_exec	*list_new_node(void)
{
	t_exec	*new;

	new = malloc(sizeof(t_exec));
	if (!new)
		return (NULL);
	new->redirection_list = NULL;
	new->cmd = NULL;
	new->option = NULL;
	new->next = NULL;
	new->input = NULL;
	new->output = NULL;
	new->fd_input = dup(STDIN_FILENO);
	new->fd_output = dup(STDOUT_FILENO);
	new->input_exist = 0;
	new->output_exist = 0;
	return (new);
}

t_exec	*list_last(t_exec *lst)
{
	t_exec	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	list_add_back(t_exec **exec, t_exec *neww)
{
	t_exec	*last;

	last = list_last(*exec);
	if (last)
		last->next = neww;
	else
		*exec = neww;
}
