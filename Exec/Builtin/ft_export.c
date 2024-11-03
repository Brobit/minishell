/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:46:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/03 22:27:56 by hehuang          ###   ########.fr       */
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
	int			append;
	t_env_list	*param;

	i = 0;
	while (params[++i])
	{
		param = find_env(env, params[i], &append);
		if (append > 0 && valid_name(params[i]))
			append_val(&param, params[i], env);
		else if ((param))
			set_value(&param, params[i]);
		else if ((params[i][0] == '_' || ft_isalpha(params[i][0]))
				&& valid_name(params[i]))
			add_end(env, new_env(params[i], NULL, NULL));
		else
			printf("export :'%s' not an valid identifier \n", params[i]);
	}
	update_env(env);
}

void	display_export(t_env_list *copy)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(copy->name, 1);
	if (!copy->val && ft_strchr_pos(copy->name, '=') == -1)
	{
	}
	else if (!copy->val || copy->val[0] == '\0')
		ft_putstr_fd("\"\"", 1);
	else
	{
		ft_putstr_fd("\"", 1);
		ft_putstr_fd(copy->val, 1);
		ft_putstr_fd("\"", 1);
	}
	ft_putchar_fd('\n', 1);
}

void	ft_export(t_env_list	**env, char **args)
{
	t_env_list	*copy;
	t_env_list	*head;
	int			i;

	i = -1;
	if (count_params(args) == 1)
	{
		copy = copy_list(*env);
		head = copy;
		sort_list(copy);
		while (copy)
		{
			if (ft_isalpha(copy->name[0]) || ft_strcmp(copy->name, "_="))
				display_export(copy);
			copy = copy->next;
		}
		free_list(head);
	}
	else
		add_to_env(args, env);
}
