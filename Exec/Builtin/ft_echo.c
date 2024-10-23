/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:20:56 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/22 23:03:37 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

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

void	ft_echo(char **msg)
{
	int	i;
	int	n;

	if (!msg)
		return ;
	n = check_option_n(msg[0]);
	i = n - 1;
	while (msg[++i])
	{
		if (i != n)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(msg[i], 1);
	}
	if (!check_option_n(msg[0]))
		ft_putchar_fd('\n', 1);
}
