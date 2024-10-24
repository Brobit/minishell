/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:57:58 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/22 23:46:00 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>
#include <unistd.h>

void	update_pwd(t_env_list **env)
{
	t_env_list	*current;
	char		cwd[1024];

	current = *env;
	dprintf(2, "PWD should be %s\n", getcwd(cwd, sizeof(cwd)));
	while (current)
	{
		if (!ft_strncmp(current->name, "OLDPWD", 6))
			current->val = find_elmt(env, "PWD")->val;
		if (!ft_strncmp(current->name, "PWD", 3))
			current->val = ft_strdup(getcwd(cwd, sizeof(cwd)));
		current = current->next;
	}
}

void	ft_cd(char **path, t_env_list **env)
{
	int		param_nb;

	(void)env;
	param_nb = count_params(path);
	if (param_nb == 1)
	{
		if (chdir(path[0]) != 0)
		{
			perror("cd");
			return ;
		}
	}
	else if (param_nb == 0)
	{
		if (chdir((find_elmt(env, "HOME"))->val) != 0)
		{
			perror("cd");
			return ;
		}
	}
	update_pwd(env);
}

void	ft_pwd(void)
{
	char	cwd[1024];

	ft_putstr_fd(getcwd(cwd, sizeof(cwd)), 2);
	ft_putchar_fd('\n', 2);
}
