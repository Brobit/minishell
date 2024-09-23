/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:19:31 by almarico          #+#    #+#             */
/*   Updated: 2024/09/23 17:05:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

t_redirection	*get_redirections(char *instruction_line)
{
	t_redirection	*redirection_list;
	int				node_number;
	int				i;

	redirection_list = NULL;
	i = 0;

	return (redirection_list);
}

void	trim_redirections(char *instruction_line)
{
	(void)instruction_line;
}

char	*get_command(char *instruction_line)
{
	char	*cmd;

	cmd = NULL;
	(void)instruction_line;
	return (cmd);
}

char	**get_option(char *instruction_line)
{
	char	**option;

	option = NULL;
	(void)instruction_line;
	return (option);
}
