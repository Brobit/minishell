/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:41:48 by almarico          #+#    #+#             */
/*   Updated: 2023/12/17 14:03:14 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_free(char *line)
{
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {};
	char		*line;
	int			res_read;

	line = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (ft_mod_strchr(buffer))
	{
		ft_cut_buffer(buffer);
		line = ft_mod_join(line, buffer);
	}
	res_read = 1;
	while (res_read > 0 && !ft_mod_strchr(buffer))
	{
		res_read = read(fd, buffer, BUFFER_SIZE);
		if (res_read == -1)
			return (ft_free(line));
		if (res_read == 0)
			return (line);
		buffer[res_read] = '\0';
		line = ft_mod_join(line, buffer);
	}
	return (line);
}
