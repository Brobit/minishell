/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:14 by almarico          #+#    #+#             */
/*   Updated: 2024/11/04 16:52:04 by almarico         ###   ########.fr       */
/*   Updated: 2024/10/27 20:19:07 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

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
	if ((*tmp)->redirection_list)
		trim_redirections(&instruction);
	(*tmp)->cmd = get_command(instruction, copy);
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
				|| (nav->redirection_list->payload[0] == '\0'
					&& !nav->redirection_list->not_null)))
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
	i = -1;
	if (check_syntax_error(input) == FAIL)
		return (FAIL);
	instructions = split_input(input, '|');
	free(input);
	while (instructions[++i])
	{
		if (!exec)
			exec = create_and_assign_node(&tmp, instructions[i], copy);
		else
			create_and_assign_node(&tmp, instructions[i], copy);
	}
	free(instructions);
	if (check_payload(&exec) == FAIL)
		return (free_exec_list(&exec), FAIL);
	ft_exec(exec, copy);
	free_exec_list(&exec);
	return (SUCCESS);
}
