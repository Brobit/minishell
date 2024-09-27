/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:14 by almarico          #+#    #+#             */
/*   Updated: 2024/09/27 10:52:17 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

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

static t_exec	*create_and_assign_node(t_exec **tmp, char *instruction)
{
	t_exec	*new_node;

	new_node = list_new_node();
	if (*tmp)
	{
		(*tmp)->next = new_node;
		*tmp = (*tmp)->next;
	}
	else
		*tmp = new_node;
	(*tmp)->redirection_list = get_redirections(instruction);
	trim_redirections(&instruction);
	(*tmp)->cmd = get_command(instruction);
	(*tmp)->option = get_option(instruction);
	return (new_node);
}

int	parser_entry(char *input, t_env *copy)
{
	t_exec	*exec;
	t_exec	*tmp;
	char	**instructions;
	int		i;

	exec = NULL;
	tmp = NULL;
	check_env_variable_and_quotes(&input, copy);
	instructions = ft_split(input, '|');
	i = 0;
	if (check_syntax_error(input) == FAIL)
		return (FAIL);
	while (instructions[i])
	{
		if (!exec)
			exec = create_and_assign_node(&tmp, instructions[i]);
		else
			create_and_assign_node(&tmp, instructions[i]);
		i++;
	}
	print_chained_list(exec);
	return (SUCCESS);
}
