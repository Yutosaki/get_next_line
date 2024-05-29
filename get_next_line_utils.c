/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:11 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/29 15:33:45 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	size_t	length;
	size_t	i;
	char	*copy;

	i = 0;
	length = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);
	while (i < length)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[length] = '\0';
	return (copy);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*j;
	size_t	js;

	if (s1 && s2)
	{
		js = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
		j = malloc(js);
		if (j)
		{
			ft_strlcpy(j, s1, ft_strlen(s1) + 1);
			ft_strlcat(j, s2, js);
			return (j);
		}
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst != NULL && size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (size == 0)
		return (src_len);
	if (dst_len < size)
	{
		i = -1;
		while (src[++i] && i + 1 < size - dst_len)
			dst[dst_len + i] = src[i];
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + size);
}
