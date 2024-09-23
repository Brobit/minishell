/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:25:44 by almarico          #+#    #+#             */
/*   Updated: 2024/09/23 16:59:14 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	check_pipes_and_ampersand(char *input)
{
	int	i;

	i = 0;
	while (input[i] && ft_isspace(input[i]) == 0)
		i++;
	if (input[i] && input[i] == '|')
		return (FAIL);
	i = ft_strlen(input) - 1;
	while (input[i] && ft_isspace(input[i]) == 0)
		i--;
	if (input[i] && input[i] == '|')
		return (FAIL);
	i = -1;
	while (input[++i])
		if ((input[i] == '|' && input[i + 1] == '|') || (input[i] == '&'))
			return (FAIL);
	return (SUCCESS);
}

int	check_space_between_pipes(char *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		if (input[i] == '|')
		{
			j = i + 1;
			while (input[i] && ft_isspace(input[j]) == 0)
				j++;
			if (input[j] == '|')
				return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_redirection_error(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i + 1] != '\0'
			&& ((input[i] == '<' && input[i + 1] == '>')
				|| (input[i] == '>' && input[i + 1] == '<')))
			return (FAIL);
		if (input[i + 1] != '\0' && input[i + 2] != '\0')
		{
			if (input[i] == '<' && input[i + 1] == '<'
				&& (input[i + 2] == '<' || input[i + 2] == '>'))
				return (FAIL);
			if (input[i] == '>' && input[i + 1] == '>'
				&& (input[i + 2] == '<' || input[i + 2] == '>'))
				return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_syntax_error(char *input)
{
	if (check_pipes_and_ampersand(input) == FAIL)
		return (FAIL);
	if (check_space_between_pipes(input) == FAIL)
		return (FAIL);
	if (check_redirection_error(input) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
