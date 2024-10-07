/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:38:48 by almarico          #+#    #+#             */
/*   Updated: 2024/10/07 18:58:41 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

static char	*ft_bandage(char c, char const *s)
{
	char	*tab;
	char	*res;

	tab = malloc(2 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = c;
	tab[1] = '\0';
	res = ft_strtrim(s, tab);
	free(tab);
	return (res);
}

static int	ft_count_malloc(char const *mem_str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (mem_str[i] != '\0')
	{
		while ((mem_str[i] != c || (mem_str[i] == c
					&& (is_in_quotes((char *)mem_str, i) == TRUE
						|| is_in_double_quotes((char *)mem_str, i) == TRUE)))
			&& mem_str[i] != '\0')
			i++;
		while (mem_str[i] == c && mem_str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void	ft_fill_res(char **res, char const *s, char c)
{
	int		j;
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (s && s[i])
	{
		j = i;
		while ((s[i] != c || (s[i] == c
					&& (is_in_quotes((char *)s, i) == TRUE
						|| is_in_double_quotes((char *)s, i) == TRUE)))
			&& s[i])
			i++;
		res[index] = ft_substr(s, j, i - j);
		while (s[i] == c && s[i])
			i++;
		index++;
	}
}

char	**split_input(char const *s, char c)
{
	char	**res;
	int		count_malloc;
	char	*tab;

	if (!s)
		return (NULL);
	tab = ft_bandage(c, s);
	if (!tab)
		return (NULL);
	count_malloc = ft_count_malloc(tab, c);
	res = ft_calloc((count_malloc + 1), sizeof(char *));
	if (!res)
		return (NULL);
	ft_fill_res(res, tab, c);
	free(tab);
	res[count_malloc] = NULL;
	return (res);
}
