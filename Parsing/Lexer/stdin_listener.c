/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:29:54 by almarico          #+#    #+#             */
/*   Updated: 2024/10/23 22:22:26 by hehuang          ###   ########.fr       */
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
		input = readline("\033[32mMinishell : \033[0m");
		if (!input)
			return (free_env(copy), free_readline(), del_curr_heredoc(), \
				exit(0));
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
		free(input);
	}
}
