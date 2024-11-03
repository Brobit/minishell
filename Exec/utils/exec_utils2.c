/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:54:22 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/03 18:27:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>
#include <unistd.h>

void	check_output(t_exec_list **exec, t_redirection	*redirect)
{
	if ((*exec)->fd_out > 2)
		close ((*exec)->fd_out);
	if (redirect->type == OUTPUT)
		(*exec)->fd_out = ft_open(redirect->payload, 1, 0);
	else
		(*exec)->fd_out = ft_open(redirect->payload, 0, 1);
	(*exec)->outfile = redirect->payload;
	if ((*exec)->fd_out == -1)
		perror((*exec)->outfile);
}

void	set_heredoc(char *name, t_exec_list **exec, int cancel)
{
	t_exec_list	*current;

	current = *exec;
	dprintf(2, "access = %d, cancel = %d\n", access(name, F_OK), cancel);
	if (cancel == 1)
	{
		while (current)
		{
			current->cancel = 1;
			current = current->next;
		}
		del_curr_heredoc();
	}
	else if (access(name, F_OK) == 0)
	{
		(*exec)->fd_in = ft_open(name, 0, 0);
		(*exec)->infile = name;
	}
	dprintf(2, "heredoc infile fd = %d\n", (*exec)->fd_in);
}

void	check_input(t_exec_list **exec, t_redirection *redirect)
{
	if ((*exec)->fd_in > 2)
		close ((*exec)->fd_in);
	if (redirect->type == INPUT)
	{
		(*exec)->fd_in = ft_open(redirect->payload, 0, 0);
		(*exec)->infile = redirect->payload;
	}
	else
	{
		setup_signal(2);
		if (redirect->payload == NULL && redirect->not_null)
			ft_here_doc("\0");
		else
			set_heredoc("heredoc.txt", exec, ft_here_doc(redirect->payload));
		setup_signal(1);
	}
	if ((*exec)->fd_in == -1)
	{
		(*exec)->args = add_str((*exec)->args, (char *)redirect->payload);
		perror((*exec)->infile);
	}
}

int	check_redirection(t_exec_list **exec)
{
	t_redirection	*current;

	current = (*exec)->redirec_list;
	while (current)
	{
		ft_printf("type : %d\tpayload : %s\n", current->type, current->payload);
		if (current->type == INPUT || current->type == HERE_DOC)
			check_input(exec, current);
		else
			check_output(exec, current);
		current = current->next;
	}
	return (SUCCESS);
}

void	dup_in_out(t_exec_list *exec)
{
	if (exec->prev && exec->fd_in <= 2)
	{
		dup2(exec->prev->pipe_fd[0], STDIN_FILENO);
		exec->fd_in = exec->prev->pipe_fd[0];
	}
	if (exec->next != NULL && exec->fd_out <= 2)
	{
		dup2(exec->pipe_fd[1], STDOUT_FILENO);
		exec->fd_out = exec->pipe_fd[1];
	}
	if (exec->fd_in > 2)
	{
		dup2(exec->fd_in, STDIN_FILENO);
		ft_close(exec->fd_in, NULL, 0);
	}
	if (exec->fd_out > 2)
	{
		dup2(exec->fd_out, STDOUT_FILENO);
		ft_close(exec->fd_out, NULL, 1);
	}
	ft_close(exec->pipe_fd[0], NULL, 0);
	ft_close(exec->pipe_fd[1], NULL, 1);
}
