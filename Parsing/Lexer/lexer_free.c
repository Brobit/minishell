/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:57:13 by almarico          #+#    #+#             */
/*   Updated: 2024/09/16 10:17:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	free_env(t_env *copy)
{
	int	i;

	i = 0;
	while (copy->env[i])
		free(copy->env[i++]);
	free(copy->env);
}

void	free_readline(void)
{
	rl_clear_history();
	rl_free_line_state();
	rl_deprep_terminal();
}
