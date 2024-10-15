/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:25:51 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/14 15:45:38 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>

int	list_size(t_env_list *mylist)
{
	int	i;

	i = 0;
	while (mylist)
	{
		mylist = mylist->next;
		i++;
	}
	return (i);
}

void	free_elmt(t_env_list **elmt)
{
	free((*elmt)->name);
	if ((*elmt)->val)
		free((*elmt)->val);
	free(*elmt);
}

void	free_list(t_env_list **list)
{
	t_env_list	*current;

	current = *list;
	while (current != NULL)
	{
		*list = (*list)->next;
		free_elmt(&current);
		current = *list;
	}
}

t_env_list	*copy_list(t_env_list *env)
{
	t_env_list	*res;
	t_env_list	*current;

	current = env->next;
	res = new_env(env->name, env->val, NULL);
	while (current != NULL)
	{
		add_end(&res, new_env(current->name, current->val, current));
		current = current->next;
	}
	return (res);
}

int	set_value(t_env_list **env, char *str, char *new_val)
{
	t_env_list	*node;
	char		*val;

	node = find_elmt(env, str);
	if (new_val)
	{
		node->val = new_val;
		return (SUCCESS);
	}
	else if (ft_strchr_pos(str, '='))
	{
		val = ft_substr(str, ft_strchr_pos(str, '='), ft_strlen(str));
		printf("new val = %s\n", val);
		if (node->val)
			free(node->val);
		(node)->val = val;
		printf("%s\n", (node)->val);
	}
	return (FAIL);
}
