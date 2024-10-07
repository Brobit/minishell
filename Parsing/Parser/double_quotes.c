/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:42:57 by almarico          #+#    #+#             */
/*   Updated: 2024/10/01 22:42:57 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	is_in_double_quotes(char *str, int i)
{
	int	index;
	int	quotes_counter;

	index = 0;
	quotes_counter = 0;
	while (index < i)
	{
		if (str[index] == '\"')
			quotes_counter++;
		index++;
	}
	if (quotes_counter % 2 != 0)
		return (TRUE);
	return (FALSE);
}
