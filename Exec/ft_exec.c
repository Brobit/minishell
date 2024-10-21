/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:42:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/21 18:43:07 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	check_builtin(t_exec *exec, t_env_list **env)
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

void	execute_cmd(t_exec_list	*exec, t_env *env, t_exec *exec_backup)
{
	static t_env_list	*env_list = NULL;
	char				**env_str;

	if (!env_list)
		env_list = create_list_from_tab(env->env);
	if (env_list && check_builtin(exec_backup, &env_list) == SUCCESS)
		exit(SUCCESS);
	else
	{
		display_exec(exec);
		execve(ft_get_path(exec->cmd, &env_list), exec->args, env_str);
		printf("\nfail\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_exec(t_exec *exec, t_env *env)
{
	t_exec_list	*exec_list;
	t_exec_list	*head;
	t_exec_list	*current;
	int			status;

	head = get_exec_list(exec);
	exec_list = head;
	while (exec_list)
	{
		pipe(exec_list->pipe_fd);
		dprintf(2, "Pipe create\n\033[33mpipe_fd[0] \033[0m= %d\n\033[33mpipe_fd[1] \033[0m= %d\n", exec_list->pipe_fd[0], exec_list->pipe_fd[1]);
		exec_list->pid = fork();
		if (exec_list->pid < 0)
		{
			perror("pid");
			return ;
		}
		else if (!exec_list->pid)
		{
			dprintf(2, "in child :\n");
			if (exec_list->prev)
			{
				dprintf(2, "DUP LAST FD : %d\n", exec_list->prev->pipe_fd[0]);
				dup2(exec_list->prev->pipe_fd[0], STDIN_FILENO);
			}
			if (exec_list->next != NULL)
				dup2(exec_list->pipe_fd[1], STDOUT_FILENO);
			current = exec_list;
			while (current)
			{
				ft_close(current->pipe_fd[0], NULL, 0);
				ft_close(current->pipe_fd[1], NULL, 1);
				current = current->prev;
			}
			check_redirection(&exec_list);
			execute_cmd(exec_list, env, exec);
		}
		exec_list = exec_list->next;
	}
	exec_list = head;
	while (exec_list)
	{
		dprintf(2, "wait for pid %d\n", exec_list->pid);
		waitpid(exec_list->pid, &status, 0);
		ft_close(exec_list->pipe_fd[0], NULL, 0);
		ft_close(exec_list->pipe_fd[1], NULL, 1);
		exec_list = exec_list->next;
	}
}
