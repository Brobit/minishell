/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:42:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/15 12:51:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>

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

char	**exec_cmd(t_exec *exec, char **env)
{
	char	**res;
	char	*tmp;
	char	**current;
	int		i;

	current = exec->option;
	i = -1;
}

void	ft_exec(t_exec *exec, t_env *env)
{
	static t_env_list	*head = NULL;
	pid_t				pid;
	char				**env_char;

	if (!head)
		head = create_list_from_tab(env->env);
	while (exec != NULL)
	{
		if (env && check_builtin(exec, &head) == SUCCESS)
			printf("builtin : %s\n", exec->cmd);
		else
		{
			printf("not in builtin\n");
			if (!exec->redirection_list)
				printf("no redirection\n");
			pid = fork();
			if (!pid)
			{
				env_char = list_to_char(&head);
				if (exec->redirection_list->type == HERE_DOC)
					ft_here_doc(exec->redirection_list->payload);
				//////exec->option = ft_split(exec->option, '');
				execve(ft_get_path(exec->cmd, &head), exec->option, env_char);
				printf("fail\n");
				exit(EXIT_FAILURE);// MAY NEED TO FREE
			}
		}
		exec = exec->next;
	}
	waitpid(pid, NULL, 0);
	printf("end\n");
}
