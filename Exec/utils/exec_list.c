/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:52:18 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 13:32:06 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

t_exec_list	*new_exec_node(t_exec *exec)
{
	t_exec_list	*res;

	res = ft_calloc(sizeof(t_exec_list), 1);
	if (!res)
		return (NULL);
	res->cmd = exec->cmd;
	res->args = get_args(exec);
	res->redirec_list = exec->redirection_list;
	return (res);
}

void	add_exec_node(t_exec_list **head, t_exec_list *new_node)
{
	t_exec_list	*current;

	if (!(*head))
		(*head) = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

t_exec_list	*get_exec_list(t_exec *exec)
{
	t_exec		*current;
	t_exec_list	*res;

	current = exec;
	res = NULL;
	while (current != NULL)
	{
		add_exec_node(&res, new_exec_node(current));
		current = current->next;
	}
	return (res);
}

/*
void	free_exec_node(t_exec_list **node)
{
	if ((*node)->outfile)
		free
	free(*node);
}
*/
void	free_ex_list(t_exec_list **head)
{
	t_exec_list	*current;

	while (head != NULL)
	{
		current = (*head)->next;
		if ((*head)->args)
			ft_free_str_list((*head)->args);
		free(*head);
		head = &current;
	}
}
