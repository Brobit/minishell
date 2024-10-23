/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:09:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 22:29:19 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>
#include <unistd.h>

void	del_curr_heredoc(void)
{
	dprintf(2, "TRYING TO DELETE HEREDOC\n");
	if (access("heredoc.txt", F_OK))
	{
		unlink("heredoc.txt");
	}
}

void	ft_here_doc(const char *delimiter)
{
	int			fd;
	char		*line;
	char		*tmp_limit;
	const char	*filename = "heredoc.txt";

	fd = ft_open(filename, 1, 0);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	tmp_limit = ft_strjoin(delimiter, "\n");
	while (1)
	{
		write(2, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strcmp(line, (char *)tmp_limit) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, strlen(line));
		free(line);
	}
	close(fd);
}
