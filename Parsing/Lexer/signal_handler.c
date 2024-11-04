/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:42:51 by almarico          #+#    #+#             */
/*   Updated: 2024/10/26 17:57:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	signal_handler_rl(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = signum + 128;
	}
}

void	signal_handler_exec(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_status = signum + 128;
	}
	else if (signum == 3)
	{
		ft_printf("Quit (core dumped)\n");
		g_exit_status = signum + 128;
	}
}

void	signal_handler_here_doc(int signum)
{
	if (signum == SIGINT)
	{
		g_exit_status = signum + 128;
	}
	if (signum == SIGQUIT)
	{
		write(1, "\b\b  \b\b", 6);
		g_exit_status = signum + 128;
	}
}
/*
int	init_signal(struct sigaction *signal, int sigerr)
{
	signal->sa_handler = signal_handler;
	signal->sa_flags = SA_RESTART;
	sigemptyset(&signal->sa_mask);
	if (sigaction(sigerr, signal, NULL))
		return (FAIL);
	return (SUCCESS);
}
*/
void	setup_signal(int state)
{
	struct sigaction	s_action_int;
	struct sigaction	s_action_quit;

	s_action_int.sa_flags = SA_RESTART;
	s_action_quit.sa_flags = SA_RESTART;
	sigemptyset(&(s_action_int.sa_mask));
	sigemptyset(&(s_action_quit.sa_mask));
	if (state == 0)
	{
		s_action_int.sa_handler = signal_handler_rl;
		s_action_quit.sa_handler = SIG_IGN;
	}
	else if (state == 1)
	{
		s_action_int.sa_handler = signal_handler_exec;
		s_action_quit.sa_handler = signal_handler_exec;
	}
	else if (state == 2)
	{
		s_action_int.sa_handler = signal_handler_here_doc;
		s_action_quit.sa_handler = signal_handler_here_doc;
		s_action_int.sa_flags = 0;
	}
	sigaction(SIGQUIT, &s_action_quit, NULL);
	sigaction(SIGINT, &s_action_int, NULL);
}
