/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:54:22 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/18 15:28:53 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

void	check_output(t_exec **exec, t_redirection *redirec)
{
	if ((*exec)->fd_output)
		close ((*exec)->fd_output);
	if (redirec->type == OUTPUT)
		(*exec)->fd_output = open(redirec->payload, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		(*exec)->fd_output = open(redirec->payload, \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if ((*exec)->fd_output == -1)
	{
		perror(redirec->payload);
	}
	else
		(*exec)->output_exist = 1;
}

void	check_input(t_exec **exec, t_redirection *redirec)
{
	if ((*exec)->fd_input || redirec->type == HERE_DOC)
		close ((*exec)->fd_input);
	if (redirec->type == INPUT)
		(*exec)->fd_input = open(redirec->payload, O_RDONLY);
	else
	{
		ft_here_doc(redirec->payload);
		if (access("heredoc.txt", F_OK) == 0)
			(*exec)->fd_input = open("heredoc.txt", O_RDONLY);
		else
			printf("cant access\n");
	}
	if ((*exec)->fd_input == -1)
	{
		perror(redirec->payload);
	}
	else
		(*exec)->input_exist = 1;
}

int	check_redirection(t_exec **exec)
{
	t_redirection	*current;

	current = (*exec)->redirection_list;
	while (current && (*exec)->fd_input >= 0 && (*exec)->fd_output >= 0)
	{
		ft_printf("redirection type : %d\tpayload : %s\n", current->type, current->payload);
		if (current->type == INPUT || current->type == HERE_DOC)
			check_input(exec, current);
		else
			check_output(exec, current);
		current = current->next;
	}
	if ((*exec)->fd_output == -1 || (*exec)->fd_input == -1)
		return (FAIL);
	return (SUCCESS);
}

void	check_pipe(t_exec **exec, int in_parent, int fd_last_pipe, int *pipe_fd)
{
	if (!in_parent)
	{
		if (fd_last_pipe != -1)
		{
			(*exec)->fd_input = fd_last_pipe;
			(*exec)->input_exist = 1;
		}
		close(pipe_fd[0]);
	}
	else
	{
		if (fd_last_pipe != -1)
			(*exec)->fd_input = -1;
		if ((*exec)->next != NULL)
		{
			close (pipe_fd[1]);
			fd_last_pipe = pipe_fd[0];
		}
	}
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
	while (res[++i])
		printf("%s\n", res[i]);
	return (res);
}
