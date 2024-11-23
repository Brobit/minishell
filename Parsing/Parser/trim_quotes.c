/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:08:27 by almarico          #+#    #+#             */
/*   Updated: 2024/11/23 12:32:05 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	is_a_quote(char c, int *state)
{
	if (c == '\'' && *state == 0)
		*state = 1;
	else if (c == '\'' && *state == 1)
		*state = 0;
	if (c == '\"' && *state == 0)
		*state = 2;
	else if (c == '\"' && *state == 2)
		*state = 0;
}

void	shift_str(char *str, int length)
{
	int	i;

	i = 0;
	while (str[i + length])
	{
		str[i] = str[i + length];
		i++;
	}
	str[i] = '\0';
}

void	trim_quotes(char **option, t_env *copy)
{
	int	i;
	int	j;
	int	state;

	state = 0;
	i = 0;
	while (option[i])
	{
		j = 0;
		while (option[i][j])
		{
			is_a_quote(option[i][j], &state);
			if ((option[i][j] == '\"' && state != 1)
				|| (option[i][j] == '\'' && state != 2))
				shift_str((option[i] + j), 1);
			if (option[i][j + (j < 0)] == '$' && state != 1)
				transform_string(&option[i], copy, &j);
			if (j >= (int)ft_strlen(option[i]))
				j = -1;
			j++;
		}
		i++;
	}
}

void	trim_command_quotes(char *cmd, t_env *copy)
{
	int	i;
	int	state;

	state = 0;
	i = 0;
	while (cmd[i])
	{
		is_a_quote(cmd[i], &state);
		if ((cmd[i] == '\"' && state != 1)
			|| (cmd[i] == '\'' && state != 2))
			shift_str((&cmd[i]), 1);
		if (cmd[i] == '$' && state != 1)
			transform_string(&cmd, copy, &i);
		if (i >= (int)ft_strlen(cmd))
			i = -1;
		i++;
	}
}

void	trim_payload_quotes(char *option)
{
	int	i;
	int	state;

	state = 0;
	i = 0;
	while (option[i])
	{
		is_a_quote(option[i], &state);
		if ((option[i] == '\"' && state != 1)
			|| (option[i] == '\'' && state != 2))
			shift_str((option + i), 1);
		else if (i < (int)ft_strlen(option))
			i++;
	}
}
