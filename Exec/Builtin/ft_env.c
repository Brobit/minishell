/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:34:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/14 15:34:49 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	ft_env(t_env_list *env)
{
	t_env_list	*current;

	current = env;
	while (current != NULL)
	{
		if (current->val && ft_strcmp("", current->val))
			printf("%s%s\n", current->name, current->val);
		else if (ft_strchr(current->name, '='))
			printf("%s\n", current->name);
		current = current->next;
	}
}
