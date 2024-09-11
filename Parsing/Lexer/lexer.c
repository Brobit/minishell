/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:38:17 by almarico          #+#    #+#             */
/*   Updated: 2024/09/11 14:55:25 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

static int	env_copy(t_global *global_struct, char **env)
{
	return (SUCCESS);
}

int	lexer_entry(char **env)
{
	t_global	global_struct;

	if (env_copy(&global_struct, env) == FAIL)
		return (free_env(&global_struct), FAIL);
	return (SUCCESS);
}
