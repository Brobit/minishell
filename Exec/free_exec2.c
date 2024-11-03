/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:58:45 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/31 21:12:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	free_child(char	**str_tab, t_exec_list *exec_list, \
				t_env_list *env_list, t_exec *exec)
{
	ft_free_str_list(str_tab);
	if (env_list->env)
		free_env(env_list->env);
	free_exec_list(&exec);
	free_all_exit(exec_list, env_list, EXIT_FAILURE);
}
