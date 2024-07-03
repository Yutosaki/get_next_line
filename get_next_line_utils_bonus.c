/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:11 by yutsasak          #+#    #+#             */
/*   Updated: 2024/07/03 13:53:50 by yutsasak         ###   ########.fr       */
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	joined_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	joined_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(sizeof(char) * joined_len);
	if (joined == NULL)
		return (NULL);
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcpy(joined + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (joined);
}
