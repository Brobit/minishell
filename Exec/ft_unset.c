/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:46:49 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/08 15:21:24 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	find_var(char	**env, char *my_var)
{
	int		i;
	int		size;
	int		len;
	char	**tmp_env;
	char	*tmp_var;

	i = -1;
	tmp_env = copy_tab(env, &size);
	tmp_var = ft_strjoin(my_var, "=");
	len = ft_strlen(tmp_var);
	while (++i < size)
	{
		if (!ft_strncmp(tmp_var, tmp_env[i], len))
		{
			free(tmp_env);
			free(tmp_var);
			return (i);
		}
		printf("%s\n", tmp_env[i]);
	}
	free(tmp_var);
	free(tmp_env);
	return (-1);
}

void	ft_unset(char	**env, char *my_var)
{
	int	index;

	index = find_var(env, my_var);
	if (index >= 0)
		remove_element(env, index);
}
