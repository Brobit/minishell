/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:08:24 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/03 18:18:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_free_str_list(char **str_list)
{
	int	i;

	i = -1;
	if (!str_list)
		return ;
	while (str_list[++i])
		free(str_list[i]);
	free(str_list);
}

void	free_elmt(t_env_list **elmt)
{
	free((*elmt)->name);
	if ((*elmt)->val)
		free((*elmt)->val);
	free(*elmt);
}

void	free_list(t_env_list *list)
{
	t_env_list	*current;

	dprintf(2, "freeing list \n");
	while (list != NULL)
	{
		current = list;
		list = list->next;
		free_elmt(&current);
	}
}

void	free_exec(t_exec_list *exec)
{
	t_exec_list	*current;


	while (exec->prev)
		exec = exec->prev;
	while (exec != NULL)
	{
		current = exec;
		exec = exec->next;
		if (current->cmd)
			free(current->cmd);
		if (current->args)
			ft_free_str_list(current->args);
		free(current);
	}
}

void	free_all_exit(t_exec_list *exec, t_env_list *env, int exit_code)
{
	if (exec)
		free_exec(exec);
	if (env)
		free_list(env);
	if (exit_code >= 0)
		exit(exit_code);
	if (access("heredoc.txt", F_OK) == 0)
		unlink("heredoc.txt");
}
