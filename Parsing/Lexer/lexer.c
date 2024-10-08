/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:38:17 by almarico          #+#    #+#             */
/*   Updated: 2024/09/16 14:47:34 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

static int	env_copy(t_env *copy, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	copy->env = malloc((i + 1) * sizeof(char *));
	if (!copy->env)
		return (error(ERR_ENV_COPY), free(copy->env), FAIL);
	copy->env[i] = NULL;
	i = -1;
	while (env[++i] != NULL)
	{
		copy->env[i] = ft_strdup(env[i]);
		if (!copy->env[i])
			return (error(ERR_ENV_DUP), free_env(copy), FAIL);
	}
	return (SUCCESS);
}

int	lexer_entry(char **env)
{
	t_env				copy;
	struct sigaction	signal;

	if (env_copy(&copy, env) == FAIL)
		return (FAIL);
	if (init_signal(&signal, SIGINT) == FAIL)
		return (free_env(&copy), FAIL);
	if (init_signal(&signal, SIGQUIT) == FAIL)
		return (free_env(&copy), FAIL);
	stdin_listener(&copy);
	return (SUCCESS);
}
