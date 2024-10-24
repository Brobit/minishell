/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:08:24 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 14:31:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_free_str_list(char **str_list)
{
	int	i;

	i = -1;
	while (str_list[i])
		free(str_list[i]);
	free(str_list);
}

void	free_elmt(t_env_list **elmt)
{
	free((*elmt)->name);
	if ((*elmt)->val)
		free((*elmt)->val);
	free(*elmt);
}

void	free_list(t_env_list **list)
{
	t_env_list	*current;

	current = *list;
	while (current != NULL)
	{
		*list = (*list)->next;
		free_elmt(&current);
		current = *list;
	}
}
