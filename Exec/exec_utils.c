/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:48:01 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/08 15:23:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

char	**copy_tab(char	**env, int *size)
{
	int		i;
	char	**copy;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
		i++;
	*size = i;
	copy = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		copy[i] = env[i];
	copy[i] = NULL;
	return (copy);
}

void	remove_element(char **tab, int index)
{
	int	i;

	i = index;
	while (tab[i + 1] != NULL)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = NULL;
}
