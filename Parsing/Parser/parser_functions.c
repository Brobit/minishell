/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:19:31 by almarico          #+#    #+#             */
/*   Updated: 2024/10/22 10:42:21 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

t_redirection	*get_redirections(char *instruction_line)
{
	t_redirection	*redirection_list;
	int				i;

	redirection_list = NULL;
	i = 0;
	while (instruction_line[i])
	{
		if (instruction_line[i] == '<' || instruction_line[i] == '>')
		{
			if (is_in_quotes(instruction_line, i) == FALSE
				&& is_in_double_quotes(instruction_line, i) == FALSE)
			{
				redirection_list_add_back(&redirection_list, \
						redirection_list_new_node());
				i += fill_redirection(redirection_list, &instruction_line[i]);
			}
		}
		if (instruction_line[i] && instruction_line[i] != '<'
			&& instruction_line[i] != '>')
			i++;
	}
	return (redirection_list);
}

void	trim_redirections(char **line)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = NULL;
	while ((*line)[i])
	{
		j = i;
		exec_trim(line, &res, &i, j);
	}
	if (res)
	{
		free((*line));
		(*line) = ft_strdup(res);
		free(res);
	}
}

char	*get_command(char *line)
{
	char	*cmd;
	char	*tmp;
	int		i;
	int		j;

	cmd = NULL;
	tmp = NULL;
	i = 0;
	while (line[i] && ft_isspace(line[i]) == 0)
		i++;
	j = i;
	while (line[j] && ft_isspace(line[j]) != 0)
		j++;
	tmp = ft_substr(line, i, j);
	cmd = ft_strtrim(tmp, " ");
	free(tmp);
	return (cmd);
}

char	**get_option(char *line, t_env *copy)
{
	char	**option;
	int		i;

	option = NULL;
	i = 0;
	while (line[i] && ft_isspace(line[i]) == 0)
		i++;
	while (line[i] && ft_isspace(line[i]) != 0)
		i++;
	if (line[i] != '\0')
		option = split_input(&line[i], ' ');
	// ft_printf("%s\n", *option);
	if (option)
		trim_quotes(option, copy);
	return (option);
}
