/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:14 by almarico          #+#    #+#             */
/*   Updated: 2024/09/26 11:12:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

void	print_chained_list(t_exec *exec)
{
	int	i;

	if (exec == NULL)
		printf("error\n");
	while (exec != NULL)
	{
		if (exec->redirection_list == NULL)
			printf("no redirection list\n");
		while (exec->redirection_list != NULL)
		{
			printf("redirection type : %d\tpayload : %s\n", exec->redirection_list->type, exec->redirection_list->payload);
			exec->redirection_list = exec->redirection_list->next;
		}
		if (exec->cmd)
			printf("cmd : %s\n", exec->cmd);
		if (exec->option == NULL)
			printf("there is no option\n");
		else
		{
			i = 0;
			while (exec->option[i] != NULL)
				printf("option : %s\n", exec->option[i++]);
		}
		exec = exec->next;
	}
}

int	parser_entry(char *input)
{
	t_exec	*exec;
	char	**instructions;
	int		i;

	if (check_syntax_error(input) == FAIL)
		return (FAIL);
	exec = NULL;
	instructions = ft_split(input, '|');
	i = 0;
	while (instructions[i])
	{
		list_add_back(&exec, list_new_node());
		exec->redirection_list = get_redirections(instructions[i]);
		trim_redirections(&instructions[i]);
		// ft_printf("%s\n", instructions[i]);
		exec->cmd = get_command(instructions[i]);
		exec->option = get_option(instructions[i]);
		i++;
	}
	print_chained_list(exec);
	return (SUCCESS);
}
