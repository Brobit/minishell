/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:57:58 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/13 18:45:47 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

void	ft_cd(char **path, t_env_list **env)
{
	int		param_nb;
	char	cwd[1024];

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
		if (chdir((*find_elmt(env, "HOME"))->val) != 0)
		{
			perror("cd");
			return ;
		}
	}
	set_value(env, "OLDPWD", (*find_elmt(env, "PWD"))->val);
	set_value(env, "PWD", getcwd(cwd, sizeof(cwd)));
}

void	ft_pwd(void)
{
	char	cwd[1024];

	ft_putstr_fd(getcwd(cwd, sizeof(cwd)), 2);
	ft_putchar_fd('\n', 2);
}
