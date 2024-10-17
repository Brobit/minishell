/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:14 by almarico          #+#    #+#             */
/*   Updated: 2024/10/17 15:40:59 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	print_chained_list(t_exec *exec)
{
	int	i;

	if (exec == NULL)
		ft_printf("error\n");
	while (exec != NULL)
	{
		if (exec->redirection_list == NULL)
			ft_printf("no redirection list\n");
		while (exec->redirection_list != NULL)
		{
			ft_printf("redirection type : %d\tpayload : %s\n", exec->redirection_list->type, exec->redirection_list->payload);
			exec->redirection_list = exec->redirection_list->next;
		}
		if (exec->cmd == NULL)
			ft_printf("there is no command\n");
		if (exec->cmd)
			ft_printf("cmd : %s\n", exec->cmd);
		if (exec->option == NULL)
			ft_printf("there is no option\n");
		else
		{
			i = 0;
			while (exec->option[i] != NULL)
				ft_printf("option : |%s|\n", exec->option[i++]);
		}
		exec = exec->next;
	}
}

static t_exec	*create_and_assign_node(t_exec **tmp, \
				char *instruction, t_env *copy)
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
	(*tmp)->option = get_option(instruction, copy);
	free(instruction);
	return (*tmp);
}

int	check_payload(t_exec **exec)
{
	t_exec	*nav;

	nav = *exec;
	while (nav)
	{
		if (nav->redirection_list && (!nav->redirection_list->payload
				|| nav->redirection_list->payload[0] == '\0'))
			return (FAIL);
		nav = nav->next;
	}
	return (SUCCESS);
}

int	parser_entry(char *input, t_env *copy)
{
	t_exec	*exec;
	t_exec	*tmp;
	char	**instructions;
	int		i;

	exec = NULL;
	tmp = NULL;
	i = 0;
	if (check_syntax_error(input) == FAIL)
		return (FAIL);
	instructions = split_input(input, '|');
	while (instructions[i])
	{
		if (!exec)
			exec = create_and_assign_node(&tmp, instructions[i], copy);
		else
			create_and_assign_node(&tmp, instructions[i], copy);
		i++;
	}
	free(instructions);
	if (check_payload(&exec) == FAIL)
		return (FAIL);
	free_exec_list(exec);
	return (SUCCESS);
}
