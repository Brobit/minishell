/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:43:44 by almarico          #+#    #+#             */
/*   Updated: 2024/11/24 11:10:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

static char	*size_free_conflict(char *input, int i, int start)
{
	char	*tmp;
	char	*res;

	tmp = ft_substr(input, start, (i - start));
	res = ft_strjoin(tmp, "=");
	free(tmp);
	return (res);
}

static char	*search_in_env(char *input, t_env *copy, int *i)
{
	char	*string;
	int		start;
	int		length;
	int		j;

	*i += 1;
	start = *i;
	while (ft_isalnum(input[*i]) != 0 || input[*i] == '_')
		*i += 1;
	string = size_free_conflict(input, *i, start);
	length = ft_strlen(string);
	j = 0;
	while (copy->env[j] && ft_strncmp(string, copy->env[j], length) != 0)
		j++;
	free(string);
	if (copy->env[j])
	{
		start = length;
		length = ft_strlen(copy->env[j]) - start;
		string = ft_substr(copy->env[j], start, length);
	}
	else
		string = ft_strdup("");
	return (string);
}

static char	*replace_by_last_exit_status(int *i, t_env *copy)
{
	char	*value;

	*i += 2;
	(void)copy;
	if (g_exit_status > 0)
	{
		value = ft_itoa(g_exit_status);
		g_exit_status = 0;
	}
	else
		value = ft_itoa(copy->last_status);
	return (value);
}

void	transform_string(char **input, t_env *copy, int *i)
{
	char	*before_variable;
	char	*variable_expension;
	char	*rest_of_string;
	char	*first_join;

	before_variable = NULL;
	variable_expension = NULL;
	rest_of_string = NULL;
	before_variable = ft_substr((*input), 0, *i);
	if ((*input)[*i + 1] == '?')
		variable_expension = replace_by_last_exit_status(i, copy);
	else if (is_in_set_to_keep((*input)[*i + 1]) == FALSE)
		variable_expension = search_in_env((*input), copy, i);
	rest_of_string = ft_substr((*input), *i, (ft_strlen((*input)) - *i));
	first_join = ft_strjoin(before_variable, variable_expension);
	free(*input);
	(*input) = ft_strjoin(first_join, rest_of_string);
	free(before_variable);
	free(variable_expension);
	free(rest_of_string);
	free(first_join);
}

void	search_and_replace_env_variable(char **input, t_env *copy)
{
	int		i;

	i = 0;
	while ((*input)[i])
	{
		if ((*input)[i] == '$')
		{
			transform_string(input, copy, &i);
			i = -1;
		}
		i++;
	}
}
