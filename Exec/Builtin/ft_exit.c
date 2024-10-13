/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:54:37 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/13 19:16:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

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
		i++;
	}
	if ((res > TLL_MAX || res < ((TLL_MAX * -1) - 1)) && *err == 0)
		*err = -1;
	return ((int)((res * neg) % 255));
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
			perror("exit");
			//EXIT PROGRAM WITH EXITCODE = 2
		}
		//QUIT PROGRAM WITH EXITCODE = param_nb
	}
	else if (param_nb > 1)
	{
		perror("exit");
		return ;
	}
	else
		return ;//QUIT PROGRAM WITH OLD EXIT CODE
}
