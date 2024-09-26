/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:19:31 by almarico          #+#    #+#             */
/*   Updated: 2024/09/26 11:16:34 by almarico         ###   ########.fr       */
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
			redirection_list_add_back(&redirection_list, \
						redirection_list_new_node());
			i += fill_redirection(redirection_list, &instruction_line[i]);
		}
		i++;
	}
	return (redirection_list);
}

void	trim_redirections(char **instruction_line)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = NULL;
	while ((*instruction_line)[i])
	{
		j = i;
		while ((*instruction_line)[i] && (*instruction_line)[i] != '<' && (*instruction_line)[i] != '>')
			i++;
		res = ft_strjoin(res, ft_substr((*instruction_line), j, (i - j)));
		while ((*instruction_line)[i] && ((*instruction_line)[i] == '<' || (*instruction_line)[i] == '>'))
			i++;
		while ((*instruction_line)[i] && ft_isspace((*instruction_line)[i]) == 0)
			i++;
		while ((*instruction_line)[i] && ft_isspace((*instruction_line)[i]) != 0)
			i++;
		if ((*instruction_line)[i] != '\0')
			i++;
	}
	free((*instruction_line));
	if (res)
		(*instruction_line) = ft_strdup(res);
}

char	*get_command(char *instruction_line)
{
	char	*cmd;
	int		i;
	int		j;

	cmd = NULL;
	i = 0;
	while (instruction_line[i] && ft_isspace(instruction_line[i]) == 0)
		i++;
	j = i;
	while (instruction_line[j] && ft_isspace(instruction_line[j]) != 0)
		j++;
	cmd = ft_substr(instruction_line, i, j);
	return (cmd);
}

char	**get_option(char *instruction_line)
{
	char	**option;
	int		i;

	option = NULL;
	i = 0;
	while (instruction_line[i] && ft_isspace(instruction_line[i]) == 0)
		i++;
	while (instruction_line[i] && ft_isspace(instruction_line[i]) != 0)
		i++;
	if (instruction_line[i] != '\0')
		option = ft_split(&instruction_line[i], ' ');
	return (option);
}
