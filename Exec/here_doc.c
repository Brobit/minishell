/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:09:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/22 13:37:47 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>

void	ft_here_doc(const char *delimiter)
{
	int			fd;
	char		*line;
	const char	*filename = "heredoc.txt";

	fd = ft_open(filename, 1, 0);
	dprintf(2, "heredoc Dlimiter = |%s|\n", delimiter);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, (char *)delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
}
