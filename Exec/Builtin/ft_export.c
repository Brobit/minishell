/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:46:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/22 22:55:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

static void	swap_var(t_env_list *a, t_env_list *b)
{
	char	*tmp_name;
	char	*tmp_val;

	tmp_name = a->name;
	tmp_val = a->val;
	a->name = b->name;
	a->val = b->val;
	b->name = tmp_name;
	b->val = tmp_val;
}

//selection sort
void	sort_list(t_env_list *head)
{
	t_env_list	*sorted;
	t_env_list	*current;
	t_env_list	*min;

	sorted = head;
	while (sorted != NULL)
	{
		min = sorted;
		current = sorted->next;
		while (current != NULL)
		{
			if (ft_strcmp(current->name, min->name) < 0)
			{
				min = current;
			}
			current = current->next;
		}
		if (min != sorted)
		{
			swap_var(min, sorted);
		}
		sorted = sorted->next;
	}
}

int	find_and_set(t_env_list	**env, char *my_var, char	*new_val)
{
	t_env_list	*current;
	int			len;

	current = *env;
	len = ft_strlen(my_var);
	while (current != NULL)
	{
		if (!ft_strncmp(current->name, my_var, len)
			&& (!my_var[len]
				|| (current->name[len] == '=' && current->name[len + 1])))
		{
			current->val = new_val;
			return (SUCCESS);
		}
		current = current->next;
	}
	return (FAIL);
}

void	add_to_env(char **params, t_env_list **env)
{
	int			i;
	t_env_list	*param;

	i = -1;
	while (params[++i])
	{
		param = find_elmt(env, params[i]);
		if ((param))
			set_value(env, params[i], NULL);
		else if (((params[i][0] == '_' && params[i][1] != '=')
			|| ft_isalpha(params[i][0])))
			add_end(env, new_env(params[i], NULL, NULL));
		else
		{
			printf("export :'%s' not an valid identifier \n", params[i]);
		}
	}
}

void	ft_export(t_env_list	**env, char **args)
{
	t_env_list	*copy;
	int			i;

	i = -1;
	if (args == NULL)
	{
		copy = copy_list(*env);
		sort_list(copy);
		while (copy)
		{
			if (ft_isalpha(copy->name[0]) || ft_strcmp(copy->name, "_="))
			{
				if (!copy->val && ft_strchr_pos(copy->name, '=') == -1)
					printf("declare -x %s\n", copy->name);
				else if (!copy->val)
					printf("declare -x %s=\"\"\n", copy->name);
				else
					printf("declare -x %s\"%s\"\n", copy->name, copy->val);
			}
			copy = copy->next;
		}
		free_list(&copy);
	}
	else
		add_to_env(args, env);
}
