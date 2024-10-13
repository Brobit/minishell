/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:57:58 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/13 21:16:24 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
/* use for test 
char	*ft_get_env(char	*name, char	**envp)
{
	int	i;
	int	n_len;
	int	env_len;

	i = -1;
	n_len = ft_strlen(name);
	while (envp[++i])
	{
		env_len = ft_strlen(envp[i]);
		if (env_len > n_len && envp[i][n_len] == '='
			&& !ft_strncmp(name, envp[i], n_len))
		{
			return (envp[i] + n_len + 1);
		}
	}
	return (NULL);
}

char	*ft_get_path(char	*cmd, char	**envp)
{
	char	**paths;
	char	*exec;
	int		i;

	i = -1;
	paths = ft_split(ft_get_env("PATH", envp), ':');
	while (paths[++i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(paths[i], cmd);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free(paths);
			return (exec);
		}
		free (exec);
	}
	free(paths);
	return (cmd);
}

void	ft_cd(char *path, char *cmd, char **envp)
{
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	if (chdir(path) != 0)
	{
		perror("cd");
		return ;
	}
	execve(ft_get_path(s_cmd[0], envp), s_cmd, envp);
}*/

void	ft_cd(char *path)
{
	if (chdir(path) != 0)
	{
		perror("cd");
		return ;
	}
}



void	ft_pwd(void)
{
	char	cwd[1024];

	ft_putstr_fd(getcwd(cwd, sizeof(cwd)), 2);
	ft_putchar_fd('\n', 2);
}
