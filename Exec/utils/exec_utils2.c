/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:54:22 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 22:07:35 by hehuang          ###   ########.fr       */
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
	{
		perror((*exec)->outfile);
	}
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
		dprintf (2, "HERE DOC DELIMITER|%s|\n", redirect->payload);
		if (ft_strcmp((char *)redirect->payload, "\"\"") == 0)//IF NULL intead of "\"\"" at least "\0"
			ft_here_doc("\0");
		else
			ft_here_doc(redirect->payload);
		if (access("heredoc.txt", F_OK) == 0)
		{
			(*exec)->fd_in = ft_open("heredoc.txt", 0, 0);
			(*exec)->infile = "heredoc.txt";
		}
		else
			printf("cant access\n");
	}
	if ((*exec)->fd_in == -1)
	{
		perror("input opening");
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
	if ((*exec)->fd_in > 2)
	{
		dup2((*exec)->fd_in, STDIN_FILENO);
		ft_close((*exec)->fd_in, (*exec)->infile, -1);
	}
	if ((*exec)->fd_out > 0)
	{
		dup2((*exec)->fd_out, STDOUT_FILENO);
		ft_close((*exec)->fd_out, (*exec)->outfile, -1);
	}
	return (SUCCESS);
}

char	**get_args(t_exec *exec)
{
	char	**res;
	int		j;
	int		i;

	i = 0;
	if (exec->option)
	{
		while (exec->option[i])
			i++;
	}
	res = malloc (sizeof(char *) * (i + 2));
	j = 0;
	res[j] = exec->cmd;
	while (++j < i + 1)
		res[j] = exec->option[j - 1];
	res[j] = NULL;
	i = -1;
	return (res);
}
