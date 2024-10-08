/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:29:34 by almarico          #+#    #+#             */
/*   Updated: 2024/10/08 14:16:06 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

volatile int	g_exit_status;

int	main(int argc, char **argv, char **env)
{
	g_exit_status = 0;
	(void)argv;
	if (argc > 1)
		return (perror(ERR_ARGC), FAIL);
	lexer_entry(env);
	return (g_exit_status);
}
