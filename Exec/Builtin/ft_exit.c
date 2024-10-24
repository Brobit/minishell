/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:54:37 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 22:37:02 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_check_atoll(const char *string, int *err)
{
	unsigned long long	neg;
	unsigned long long	res;
	int					i;

	res = 0;
	i = 0;
	neg = 1;
	while ((string[i] >= '\t' && string[i] <= '\r') || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			neg *= -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		res *= 10;
		res += (string[i] - '0');
		if ((res > TLL_MAX || res < ((TLL_MAX * -1) - 1)) && string[i] != '\0')
			*err = -1;
		i++;
	}
	return ((int)((res * neg) % 255));
}

void	exit__with_code(int exit_code, int exit_bool)
{
	g_exit_status = exit_code;
	if (exit_bool)
		exit(exit_code);
}

void	ft_exit(char	**exit_code)
{
	int	err;
	int	res_signal;
	int	param_nb;

	err = 0;
	param_nb = count_params(exit_code);
	if (param_nb == 1)
	{
		res_signal = ft_check_atoll(exit_code[0], &err);
		if (err == -1)
		{
			write(2, EXIT_NO_NUM_ERR, ft_strlen(EXIT_NO_NUM_ERR));
			exit__with_code(2, TRUE);
		}
		exit__with_code(res_signal, TRUE);
	}
	else if (param_nb > 1)
	{
		write(2, EXIT_ARGS_ERROR, ft_strlen(EXIT_ARGS_ERROR));
		exit__with_code(1, FALSE);
	}
	else
		exit__with_code(EXIT_SUCCESS, TRUE);
}
