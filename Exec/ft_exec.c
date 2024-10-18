/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:42:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/18 15:37:38 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>
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

void	exec_cmd(t_exec *exec, t_env_list *head)
{
	char	**env_str;
	char	**fuse;

	if (exec->input_exist)
	{
		if (dup2 (exec->fd_input, STDIN_FILENO) == -1)
			perror("dup2 input need to exit");
		close(exec->fd_input);
	}
	if (exec->output_exist)
	{
		if (dup2(exec->fd_output, STDOUT_FILENO) == -1)
			perror ("dup2 output need to exit");
		close(exec->fd_output);
	}
	if (head && check_builtin(exec, &head) == SUCCESS)
		printf("builtin : %s\n", exec->cmd);
	else
	{
		env_str = list_to_char(&head);
		fuse = get_args(exec);
		execve(ft_get_path(exec->cmd, &head), fuse, env_str);
		printf("fail\n");
	}
}

void	ft_parent_process(t_exec *exec, int last_fd, int *pipe_fd, pid_t	pid)
{
	waitpid(pid, NULL, 0);
	check_pipe(&exec, 1, last_fd, pipe_fd);
	printf("parent\n");
	if (access("heredoc.text", F_OK))
		unlink("heredoc.txt");
}

void	ft_pipe(t_exec *exec, t_env_list *head)
{
	pid_t				pid;
	int					pipe_fd[2];
	int					last_fd;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(FAIL);
	}
	last_fd = -1;
	pid = fork();
	if (!pid)
	{
		check_pipe(&exec, 0, last_fd, pipe_fd);
		if (exec->redirection_list)
			check_redirection(&exec);
		exec_cmd(exec, head);
	}
	else if (pid < 0)
	{
		perror("pid");
		return ;
	}
	else
		ft_parent_process(exec, last_fd, pipe_fd, pid);
}

void	ft_exec(t_exec *exec, t_env *env)
{
	static t_env_list	*head = NULL;

	if (!head)
		head = create_list_from_tab(env->env);
	while (exec != NULL)
	{
		ft_pipe(exec, head);
		exec = exec->next;
	}
}
