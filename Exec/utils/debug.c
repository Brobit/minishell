/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:33:23 by hehuang           #+#    #+#             */
/*   Updated: 2024/10/23 13:42:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
#include <stdio.h>

void	display_exec(t_exec_list *exec)
{
	int	i;

	i = -1;
	dprintf(2, "---------DISPLAY EXEC----------\n");
	dprintf(2, "cmd = %s|\n", exec->cmd);
	while (exec->args[++i])
		dprintf(2, "args[%d] = %s|\n", i, exec->args[i]);
	dprintf(2, "---------DISPLAY END-----------\n");
}

void	ft_close(int fd, const char *filename, int pipe_entry)
{
	if (fd > 2)
		close(fd);
	if (pipe_entry != -1)
		dprintf(2, "\033[34mClosing pipe_fd[%d] \033[0m=> fd : %d\n", pipe_entry, fd);
	else
		dprintf(2, "\033[34mClosing %s \033[0m=> fd : %d\n", filename, fd);
}

int	ft_open(const char *filename, int trunc, int append)
{
	int	fd;

	if (trunc)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (fd == 0)
		dprintf(2, "\033[31mWARNING STDIN CLOSED PREVIOUSLY\033[0m\n");
	else if (fd == 1)
		dprintf(2, "\033[31mWARNING STDOUT CLOSED PREVIOUSLY\033[0m\n");
	else if (fd == 2)
		dprintf(2, "\033[31mWARNING STDERR CLOSED PREVIOUSLY\033[0m\n");
	dprintf(2, "\033[33mOpening %s \033[0m=> fd : %d\n", filename, fd);
	return (fd);
}
