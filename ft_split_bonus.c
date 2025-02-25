/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:29:48 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 11:51:17 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	count_words(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i] != '\0')
		{
			counter++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	return (counter);
}

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	leng;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	leng = ft_strlen(s) - start;
	if (leng >= len)
		leng = len;
	sub = malloc(sizeof(char) * leng + 1);
	if (sub == NULL)
		return (NULL);
	while (s[start] && i < leng)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*extract_word(char *str, char c, int *sep_pos)
{
	int		start;
	int		word_len;
	char	*word;

	while (str[*sep_pos] == c)
		(*sep_pos)++;
	start = *sep_pos;
	word_len = 0;
	while (str[*sep_pos] != c && str[*sep_pos] != '\0')
	{
		(*sep_pos)++;
		word_len++;
	}
	word = ft_substr(str, start, word_len);
	return (word);
}

static void	free_words(char **p, int num)
{
	if (p == NULL || *p == NULL)
		return ;
	while (num > 0)
	{
		num--;
		free(p[num]);
	}
	free(p);
}

char	**ft_split(char *str, char c)
{
	int		word_count;
	int		word_index;
	int		sep_pos;
	char	**p;

	sep_pos = 0;
	word_count = count_words(str);
	p = malloc(sizeof(char *) * (word_count + 1));
	if (p == NULL)
		return (NULL);
	word_index = 0;
	while (word_index < word_count)
	{
		p[word_index] = extract_word(str, c, &sep_pos);
		if (p[word_index] == NULL)
		{
			free_words(p, word_index);
			return (NULL);
		}
		word_index++;
	}
	p[word_index] = NULL;
	return (p);
}
