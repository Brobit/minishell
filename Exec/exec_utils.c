/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:48:01 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/14 16:55:44 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_get_path(char	*cmd, t_env_list **env)
{
	char	**paths;
	char	*exec;
	int		i;

	i = -1;
	paths = ft_split(find_elmt(env, "PATH")->val, ':');
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

int	ft_strchr_pos(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i + 1);
	return (-1);
}

int	count_params(char	**params)
{
	int	i;

	i = 0;
	if (!params)
		return (i);
	while (params[i])
		i++;
	return (i);
}

char	**list_to_char(t_env_list **env)
{
	int			len;
	int			i;
	char		**res;
	t_env_list	*current;

	len = list_size(*env);
	res = malloc(sizeof(char *) * len);
	current = *env;
	i = -1;
	while (++i < len)
	{
		res[i] = ft_strjoin(current->name, current->val);
		current = current->next;
	}
	res[len - 1] = NULL;
	return (res);
}
