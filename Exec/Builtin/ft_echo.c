/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:20:56 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/03 17:03:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <unistd.h>

int	check_option_n(char *str)
{
	int	i;

	i = 0;
	if (str && str[i] == '-')
	{
		i++;
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

void	ft_echo(t_exec_list *exec)
{
	int	i;
	int	n;

	if (!exec->args[1])
	{
		write(1, "\n", 1);
		return ;
	}
	display_exec(exec);
	n = check_option_n(exec->args[1]);
	i = n;
	while (exec->args[++i])
	{
		if (i - 1 != n)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(exec->args[i], 1);
	}
	if (!check_option_n(exec->args[0]))
		ft_putchar_fd('\n', 1);
}
