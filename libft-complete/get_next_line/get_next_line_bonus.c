/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:41:48 by almarico          #+#    #+#             */
/*   Updated: 2023/12/17 14:03:44 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnlb.h"

char	*ft_free_mfd(char *line)
{
	free(line);
	return (NULL);
}

char	*get_next_line_multiple_fd(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1] = {};
	char		*line;
	int			res_read;

	line = NULL;
	if (BUFFER_SIZE < 0 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	if (ft_mod_strchr_mfd(buffer[fd]))
	{
		ft_cut_buffer_mfd(buffer[fd]);
		line = ft_mod_join_mfd(line, buffer[fd]);
	}
	res_read = 1;
	while (res_read > 0 && !ft_mod_strchr_mfd(buffer[fd]))
	{
		res_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (res_read == -1)
			return (ft_free_mfd(line));
		if (res_read == 0)
			return (line);
		buffer[fd][res_read] = '\0';
		line = ft_mod_join_mfd(line, buffer[fd]);
	}
	return (line);
}
