/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:14 by almarico          #+#    #+#             */
/*   Updated: 2024/09/17 17:25:39 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	parser_entry(char *input)
{
	t_exec	*exec;
	char	**instructions;
	int		i;

	exec = NULL;
	instructions = ft_split(input, '|');
	i = 0;
	while (instructions[i])
	{
		list_add_back(&exec, list_new_node());
		exec.redirection_list = get_redirections(instructions[i]);
		trim_redirections(instructions[i]);
		exec.cmd = get_command(instructions[i]);
		exec.option = get_option(instructions[i]);
		i++;
	}
	return (SUCCESS);
}
