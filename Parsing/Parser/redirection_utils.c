/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:30:09 by almarico          #+#    #+#             */
/*   Updated: 2024/09/25 10:50:56 by almarico         ###   ########.fr       */
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
	while (ft_isspace(instruction_line[i]) == 0)
		i++;
	j = i;
	while (ft_isspace(instruction_line[j]) != 0)
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
