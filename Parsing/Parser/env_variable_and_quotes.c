/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable_and_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:43:44 by almarico          #+#    #+#             */
/*   Updated: 2024/09/28 00:51:06 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

static char	*search_in_env(char *input, t_env *copy, int *i)
{
	char	*string;
	int		start;
	int		length;
	int		j;

	*i += 1;
	start = *i;
	while (ft_isspace(input[*i]) != 0)
		*i += 1;
	string = ft_substr(input, start, (*i - start));
	length = ft_strlen(string);
	j = 0;
	while (copy->env[j] && ft_strncmp(string, copy->env[j], length) != 0)
		j++;
	if (copy->env[j])
	{
		start = length + 1;
		length = ft_strlen(copy->env[j]) - start;
		string = ft_substr(copy->env[j], start, length);
	}
	else
		string = ft_strdup("");
	return (string);
}

static void	search_and_replace_env_variable(char **input, t_env *copy)
{
	int		i;
	char	*before_variable;
	char	*variable_expension;
	char	*rest_of_string;

	i = 0;
	before_variable = NULL;
	variable_expension = NULL;
	rest_of_string = NULL;
	while ((*input)[i])
	{
		if ((*input)[i] == '$')
		{
			before_variable = ft_substr((*input), 0, i);
			variable_expension = search_in_env((*input), copy, &i);
			rest_of_string = ft_substr((*input), i, (ft_strlen((*input)) - i));
			free((*input));
			(*input) = ft_strjoin(ft_strjoin(before_variable, \
									variable_expension), rest_of_string);
			i = -1;
		}
		i++;
	}
	free(before_variable);
	free(variable_expension);
	free(rest_of_string);
}

void	check_env_variable_and_quotes(char **input, t_env *copy)
{
	ft_printf("input before evironment expension : %s\n", (*input));
	search_and_replace_env_variable(input, copy);
	ft_printf("input after evironment expension : %s\n", (*input));
}
