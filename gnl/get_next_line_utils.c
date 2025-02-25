/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:59:24 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 13:57:35 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;
	size_t	j;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	j = 0;
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdupp(char *str)
{
	size_t	len;
	int		i;
	char	*p;

	i = 0;
	len = ft_strlen(str);
	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[len] = '\0';
	return (p);
}

char	*handle_buffer(char *store, char *buf)
{
	char	*tmp;

	if (!store)
		store = ft_strdupp(buf);
	else
	{
		tmp = ft_strjoin(store, buf);
		free(store);
		store = tmp;
	}
	return (store);
}
