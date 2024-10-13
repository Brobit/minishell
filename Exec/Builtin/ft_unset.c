/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:46:49 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/11 19:28:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

int	find_and_rm(t_env_list	**env, char *my_var)
{
	t_env_list	*current;

	current = *env;
	while (current != NULL)
	{
		if (!ft_strcmp(current->name, my_var))
		{
			rm_elmt(env, current);
			return (SUCCESS);
		}
		current = current->next;
	}
	return (FAIL);
}

void	ft_unset(t_env_list	**env, char **params)
{
	int	i;

	i = -1;
	while (params[++i])
	{
		find_and_rm(env, params[i]);
	}
}
