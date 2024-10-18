/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:33:23 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/17 11:04:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

void	display_exec(t_exec *exec)
{
	int		i;
	int		j;
	t_exec	*current;

	i = -1;
	j = 0;
	current = exec;
	while (current)
	{
		printf(">==========%d===========<\n", ++j);
		printf("cmd = %s\nredirection = %d\n", current->cmd, current->redirection_list->type);
		while (current->option[++i])
			printf("option %d : %s\n", i, current->option[i]);
		printf(">======================<\n");
		current = current->next;
	}
}
