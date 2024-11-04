/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:10:03 by almarico          #+#    #+#             */
/*   Updated: 2024/11/04 14:45:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

char	*keep_intact(char **input, int *i)
{
	int	beginning;

	beginning = *i;
	while (!ft_isspace((*input)[*i]))
		*i += 1;
	return (ft_substr(*input, beginning, *i - beginning));
}

int	is_in_set_to_keep(char c)
{
	if (c == ' ' || c == '.' || c == '+' || c == '-'
		|| c == '*' || c == '/' || c == '%' || c == '\0')
		return (TRUE);
	return (FALSE);
}
