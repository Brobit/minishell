/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:42:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 22:00:55 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	exec_builtin(t_exec *exec, t_env_list **env)
{
	if (!ft_strcmp(exec->cmd, "echo"))
		ft_echo(exec->option);
	else if (!ft_strcmp(exec->cmd, "cd"))
		ft_cd(exec->option, env);
	else if (!ft_strcmp(exec->cmd, "exit"))
		ft_exit(exec->option);
	else if (!ft_strcmp(exec->cmd, "unset"))
		ft_unset(env, exec->option);
	else if (!ft_strcmp(exec->cmd, "export"))
		ft_export(env, exec->option);
	else if (!ft_strcmp(exec->cmd, "env"))
		ft_env(*env);
	else if (!ft_strcmp(exec->cmd, "pwd"))
		ft_pwd();
	else
		return (FAIL);
	return (SUCCESS);
}

int	check_builtin(t_exec *exec)
{
	if (!ft_strcmp(exec->cmd, "echo"))
		return (SUCCESS);
	else if (!ft_strcmp(exec->cmd, "cd"))
		return (SUCCESS);
	else if (!ft_strcmp(exec->cmd, "exit"))
		return (SUCCESS);
	else if (!ft_strcmp(exec->cmd, "unset"))
		return (SUCCESS);
	else if (!ft_strcmp(exec->cmd, "export"))
		return (SUCCESS);
	else if (!ft_strcmp(exec->cmd, "env"))
		return (SUCCESS);
	else if (!ft_strcmp(exec->cmd, "pwd"))
		return (SUCCESS);
	else
		return (FAIL);
}

void	execute_cmd(t_exec_list	*exec_list, t_env_list **env_list, t_exec *exec)
{
	char				**env_str;

	env_str = list_to_char(env_list);
	dprintf(2, "Executing %s\n", exec_list->cmd);
	if (env_list && check_builtin(exec) == SUCCESS)
	{
		exec_builtin(exec, env_list);
		exit(EXIT_SUCCESS);
	}
	else
	{
		execve(ft_get_path(exec_list->cmd, env_list), exec_list->args, env_str);
		write(2, exec_list->cmd, ft_strlen(exec_list->cmd));
		write(2, ERR_CMD_NOT_FOUND, ft_strlen(ERR_CMD_NOT_FOUND));
		exit(EXIT_FAILURE);
	}
}

void	parent_process(t_exec_list **exec_list)
{
	t_exec_list	*current;

	current = *exec_list;
	while (current)
	{
		waitpid(current->pid, (int *)&g_exit_status, 0);
		ft_close(current->pipe_fd[0], NULL, 0);
		ft_close(current->pipe_fd[1], NULL, 1);
		current = current->next;
	}
}

void	child_process(t_exec_list **exec_list, \
			t_env_list **env_list, t_exec *exec)
{
	t_exec_list	*current;

	pipe((*exec_list)->pipe_fd);
	(*exec_list)->pid = fork();
	if ((*exec_list)->pid < -1)
	{
		perror("pid");
		return ;
	}
	else if (!(*exec_list)->pid)
	{
		if ((*exec_list)->prev)
			dup2((*exec_list)->prev->pipe_fd[0], STDIN_FILENO);
		if ((*exec_list)->next != NULL)
			dup2((*exec_list)->pipe_fd[1], STDOUT_FILENO);
		current = (*exec_list);
		while (current)
		{
			ft_close(current->pipe_fd[0], NULL, 0);
			ft_close(current->pipe_fd[1], NULL, 1);
			current = current->prev;
		}
		check_redirection(exec_list);
		execute_cmd(*exec_list, env_list, exec);
	}
}

void	ft_exec(t_exec *exec, t_env *env)
{
	t_exec_list			*exec_list;
	t_exec_list			*head;

	head = get_exec_list(exec);
	exec_list = head;
	if (!env->head)
		env->head = create_list_from_tab(env->env);
	if (exec_list->next == NULL && check_builtin(exec) == SUCCESS)
	{
		dprintf(2, "single exec with builtins\n");
		exec_builtin(exec, &(env->head));
	}
	else
	{
		while (exec_list)
		{
			child_process(&exec_list, &(env->head), exec);
			exec_list = exec_list->next;
		}
		parent_process(&head);
	}
}
