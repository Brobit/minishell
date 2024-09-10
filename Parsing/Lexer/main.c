/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:29:34 by almarico          #+#    #+#             */
/*   Updated: 2024/09/10 16:38:03 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)env;
	if (argc > 1)
		return (perror(ERR_ARGC), FAIL);
	return (SUCCESS);
}
