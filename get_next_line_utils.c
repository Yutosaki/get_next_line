/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:07:11 by yutsasak          #+#    #+#             */
/*   Updated: 2024/05/24 20:02:17 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*copy;
	size_t	i;

	length = ft_strlen(s1);
	copy = (char *)malloc(length + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[length] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;
	size_t	i;
	size_t	j;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[len1 + len2] = '\0';
	if (s1)
		free(s1);
	return (joined);
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
