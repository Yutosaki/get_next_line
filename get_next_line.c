/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:53:00 by yutsasak          #+#    #+#             */
/*   Updated: 2024/10/20 17:44:21 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_free(ssize_t bytes_read, char *buffer)
{
	if (bytes_read == 0 && buffer[0])
		return (buffer);
	free(buffer);
	return (NULL);
}

static char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	char	*newline;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	newline = ft_strchr(buffer, '\n');
	while (newline == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (handle_free(bytes_read, buffer));
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(buffer, buf);
		if (tmp == NULL)
		{
			free(buffer);
			return (NULL);
		}
		free(buffer);
		buffer = tmp;
		newline = ft_strchr(buffer, '\n');
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
		line = (char *)malloc(sizeof(char) * (ft_strlen(*buffer) + 2));
		if (!line)
			return (NULL);
		ft_strcpy(line, *buffer);
		line[ft_strlen(*buffer)] = '\n';
		line[ft_strlen(*buffer) + 1] = '\0';
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
	static char	*buffer[OPEN_MAX];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!buffer[fd])
	{
		temp = ft_strdup("");
		if (!temp)
			return (NULL);
		buffer[fd] = temp;
	}
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(&buffer[fd]);
	return (line);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
