/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:12:33 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/26 12:52:22 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer, char *line)
{
	char	*res;
	char	*tmp;
	char	*pos_n;

	pos_n = ft_strchr(buffer, '\n');
	if (!pos_n)
		pos_n = buffer + ft_strlen(buffer) - 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, pos_n + 1, ft_strlen(pos_n + 1) + 1);
	if (ft_strchr(buffer, '\n'))
		pos_n[1] = '\0';
	res = ft_strjoin(line, buffer);
	free(line);
	ft_bzero(buffer, BUFFER_SIZE * sizeof(char));
	ft_strlcpy(buffer, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			sz;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	sz = BUFFER_SIZE;
	if (!*buffer)
		sz = read(fd, buffer, BUFFER_SIZE);
	line = ft_strdup("");
	while (!ft_strchr(buffer, '\n') && sz > 0)
	{
		line = ft_get_line(buffer, line);
		if (!line)
			return (free(line), NULL);
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz >= 0)
			buffer[sz] = '\0';
	}
	if (sz <= 0 && *line == '\0')
		return (free(line), NULL);
	return (ft_get_line(buffer, line));
}
