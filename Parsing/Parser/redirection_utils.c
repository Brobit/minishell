/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:30:09 by almarico          #+#    #+#             */
/*   Updated: 2024/10/21 15:01:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	fill_payload(t_redirection *tmp, char *instruction_line)
{
	int	i;
	int	j;

	i = 0;
	while (instruction_line[i]
		&& (instruction_line[i] == '<' || instruction_line[i] == '>'))
		i++;
	while (instruction_line[i] && ft_isspace(instruction_line[i]) == 0)
		i++;
	j = i;
	while (instruction_line[i] && ft_isspace(instruction_line[j]) != 0
		&& (instruction_line[j] != '<' && instruction_line[j] != '>'))
		j++;
	tmp->payload = ft_substr(instruction_line, i, (j - i));
	return (j);
}

int	fill_redirection(t_redirection *redirection_list, char *instruction_line)
{
	t_redirection	*tmp;
	int				i;

	i = 0;
	tmp = redirection_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (instruction_line[i] == '<' && instruction_line[i + 1] == '<')
		tmp->type = HERE_DOC;
	else if (instruction_line[i] == '>' && instruction_line[i + 1] == '>')
		tmp->type = APPEND;
	else if (instruction_line[i] == '<')
		tmp->type = INPUT;
	else if (instruction_line[i] == '>')
		tmp->type = OUTPUT;
	i += fill_payload(tmp, instruction_line);
	return (i);
}

void	pass_redirection_and_payload(char **line, int *i)
{
	while ((*line)[*i] && ((*line)[*i] == '<' || (*line)[*i] == '>'))
		*i += 1;
	while ((*line)[*i] && ft_isspace((*line)[*i]) == 0)
		*i += 1;
	while ((*line)[*i] && ft_isspace((*line)[*i]) != 0
		&& (*line)[*i] != '<' && (*line)[*i] != '>')
		*i += 1;
	if ((*line)[*i] != '\0' && (*line)[*i] != '<' && (*line)[*i] != '>')
		*i += 1;
}

void	exec_trim(char **line, char **res, int *i, int j)
{
	char	*sub_str;
	char	*tmp;

	tmp = NULL;
	if (*res != NULL)
	{
		tmp = ft_strdup(*res);
		free(*res);
		*res = NULL;
	}
	while ((*line)[*i] && (*line)[*i] != '<' && (*line)[*i] != '>')
		*i += 1;
	sub_str = ft_substr((*line), j, (*i - j));
	if ((*line)[*i] == '\0')
		*res = ft_strjoin(tmp, sub_str);
	else if ((*line)[*i] && is_in_quotes((*line), *i) == FALSE
		&& is_in_double_quotes((*line), *i) == FALSE)
		*res = ft_strjoin(tmp, sub_str);
	free(tmp);
	free(sub_str);
	pass_redirection_and_payload(line, i);
}
