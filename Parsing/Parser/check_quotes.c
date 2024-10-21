/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:57:16 by almarico          #+#    #+#             */
/*   Updated: 2024/10/21 17:04:49 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

static void	go_to_end_of_quote(char *input, \
							int *index, int *simple_quote_number)
{
	*simple_quote_number += 1;
	*index += 1;
	while (input[*index] && input[*index] != '\'')
		*index += 1;
	if (input[*index] == '\'')
		*simple_quote_number += 1;
	if (input[*index] != '\0')
		*index += 1;
}

static void	go_to_end_of_double_quote(char *input, \
							int *index, int *double_quote_number)
{
	*double_quote_number += 1;
	*index += 1;
	while (input[*index] && input[*index] != '\"')
		*index += 1;
	if (input[*index] == '\"')
		*double_quote_number += 1;
	if (input[*index] != '\0')
		*index += 1;
}

int	check_quotes(char *input)
{
	int	index;
	int	simple_quote_number;
	int	double_quote_number;

	index = 0;
	simple_quote_number = 0;
	double_quote_number = 0;
	while (input[index])
	{
		if (input[index] && input[index] == '\'')
			go_to_end_of_quote(input, &index, &simple_quote_number);
		else if (input[index] && input[index] == '\"')
			go_to_end_of_double_quote(input, &index, &double_quote_number);
		else
			index++;
	}
	if (simple_quote_number % 2 != 0 || double_quote_number % 2 != 0)
		return (FAIL);
	return (SUCCESS);
}
