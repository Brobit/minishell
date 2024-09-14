/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:57:13 by almarico          #+#    #+#             */
/*   Updated: 2024/09/14 12:06:07 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	free_env(t_env *copy)
{
	int	i;

	i = 0;
	while (copy->env[i])
		free(copy->env[i++]);
	free(copy->env);
}
