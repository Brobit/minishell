/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:43:06 by almarico          #+#    #+#             */
/*   Updated: 2024/10/02 11:44:20 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	is_in_quotes(char *str, int i)
{
	int	index;
	int	quotes_counter;

	index = 0;
	quotes_counter = 0;
	while (index < i)
	{
		if (str[index] == '\'')
			quotes_counter++;
		index++;
	}
	if (quotes_counter % 2 != 0)
		return (TRUE);
	return (FALSE);
}

int	is_interpreted(char *str, int i)
{
	int		index;
	int		quotes_counter;
	char	first;

	index = i - 1;
	quotes_counter = 0;
	first = 0;
	while (index >= 0)
	{
		if (str[index] == '\'')
		{
			if (first == 0)
				first = '\'';
			quotes_counter++;
		}
		else if (str[index] == '\"')
		{
			if (first == 0)
				first = '\"';
		}
		index--;
	}
	if (first == '\'' && quotes_counter % 2 != 0)
		return (FALSE);
	return (TRUE);
}
