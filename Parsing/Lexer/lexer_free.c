/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:57:13 by almarico          #+#    #+#             */
/*   Updated: 2024/09/11 14:58:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	free_env(t_global *global_struct)
{
	int	i;

	i = 0;
	while (global_struct->env[i])
		free(global_struct->env[i++]);
	free(global_struct->env);
}
