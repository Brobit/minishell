/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:42:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/12 20:37:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>

int	check_builtin(t_exec *exec, t_env_list **env)
{
	(void)env;
	if (!ft_strcmp(exec->cmd, "echo"))
		ft_echo(exec->option);
	if (!ft_strcmp(exec->cmd, "cd"))
		ft_cd(exec->option, env);
	if (!ft_strcmp(exec->cmd, "exit"))
		ft_exit(exec->option);
	if (!ft_strcmp(exec->cmd, "unset"))
		ft_unset(env, exec->option);
	if (!ft_strcmp(exec->cmd, "export"))
		ft_export(env, exec->option);
	if (!ft_strcmp(exec->cmd, "env"))
		ft_env(*env);
	if (!ft_strcmp(exec->cmd, "pwd"))
		ft_pwd();
	return (0);
}

void	ft_exec(t_exec *exec, t_env *env)
{
	static t_env_list	*head = NULL;

	printf("in exec\n");
	if (!head)
		head = create_list_from_tab(env->env);
	if (env && !check_builtin(exec, &head))
		return ;
}
