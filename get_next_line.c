/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:53:00 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/24 20:08:56 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	char	*newline;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	while ((newline = ft_strchr(buffer, '\n')) == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (bytes_read == 0 && buffer[0] ? buffer : NULL);
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(buffer, buf);
		if (!tmp)
			return (NULL);
		buffer = tmp;
	}
	return (buffer);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline;
	char	*remainder;

	newline = ft_strchr(*buffer, '\n');
	if (newline)
	{
		*newline = '\0';
		line = ft_strdup(*buffer);
		remainder = ft_strdup(newline + 1);
		free(*buffer);
		*buffer = remainder;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(&buffer[fd]);
	return (line);
}