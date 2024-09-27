/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:19:31 by almarico          #+#    #+#             */
/*   Updated: 2024/09/27 10:32:22 by almarico         ###   ########.fr       */
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
		while ((*line)[i] && (*line)[i] != '<' && (*line)[i] != '>')
			i++;
		res = ft_strjoin(res, ft_substr((*line), j, (i - j)));
		while ((*line)[i] && ((*line)[i] == '<' || (*line)[i] == '>'))
			i++;
		while ((*line)[i] && ft_isspace((*line)[i]) == 0)
			i++;
		while ((*line)[i] && ft_isspace((*line)[i]) != 0)
			i++;
		if ((*line)[i] != '\0')
			i++;
	}
	free((*line));
	if (res)
		(*line) = ft_strdup(res);
}

char	*get_command(char *line)
{
	char	*cmd;
	int		i;
	int		j;

	cmd = NULL;
	i = 0;
	while (line[i] && ft_isspace(line[i]) == 0)
		i++;
	j = i;
	while (line[j] && ft_isspace(line[j]) != 0)
		j++;
	cmd = ft_substr(line, i, j);
	return (cmd);
}

char	**get_option(char *line)
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
		option = ft_split(&line[i], ' ');
	return (option);
}
