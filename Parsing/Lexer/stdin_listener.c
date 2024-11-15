/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:29:54 by almarico          #+#    #+#             */
/*   Updated: 2024/11/14 10:57:13 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	stdin_listener(t_env *copy)
{
	char	*input;

	input = NULL;
	rl_catch_signals = 0;
	while (1)
	{
		setup_signal(0);
		input = readline("\033[32mMinishell : \033[0m");
		if (!input)
			return (free_all_exit(NULL, copy->head, -1), free_env(copy), \
			free_readline(), del_curr_heredoc(), exit(0));
		else if (input && input[0] != '\0')
		{
			add_history(input);
			if (parser_entry(input, copy) == FAIL)
			{
				ft_printf("syntax error\n");
				rl_replace_line("", 1);
				rl_redisplay();
			}
		}
	}
	free(input);
}
