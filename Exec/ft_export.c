/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:46:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/09/17 23:48:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdlib.h>

static void	swap_tab_var(char **tab, int i, int j)
{
	char	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}
//selection sort
static void	sort_tab(char **tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[j], tab[min]) < 0)
				min = j;
			j++;
		}
		if (min != i)
			swap_tab_var(tab, i, min);
		i++;
	}
}

void	ft_export(char	**env)
{
	char	**copy;
	int		size;
	int		i;

	i = -1;
	copy = copy_tab(env, &size);
	sort_tab(copy, size);
	while (++i < size)
	{
		ft_putstr_fd(copy[i], 2);
		ft_putchar_fd('\n', 2);
	}
	free(copy);
}

void	ft_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putstr_fd(env[i], 2);
		ft_putchar_fd('\n', 2);
	}
}
