/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:26:47 by almarico          #+#    #+#             */
/*   Updated: 2024/09/24 14:28:13 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	free_instructions(char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i] != NULL)
		free(instructions[i]);
	free(instructions);
}
