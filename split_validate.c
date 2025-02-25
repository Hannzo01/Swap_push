/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:06:09 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 13:56:11 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_and_validate_args(int argc, char *argv[], char **split_values)
{
	char	**tmp_values;

	int (i), (k), (word_index);
	i = 1;
	word_index = 0;
	while (i < argc)
	{
		tmp_values = ft_split(argv[i], ' ');
		if (!tmp_values)
			return (1);
		if (ft_is_valid(tmp_values) == 0)
			return (free_2d_arr(tmp_values), write(2, "Error\n", 6), 1);
		k = 0;
		while (tmp_values[k] != NULL)
		{
			split_values[word_index] = ft_strdup(tmp_values[k]);
			if (split_values[word_index] == NULL)
				return (free_2d_arr(split_values), free_2d_arr(tmp_values), 1);
			k++;
			word_index++;
		}
		free_2d_arr(tmp_values);
		i++;
	}
	return (split_values[word_index] = NULL, 0);
}

void	fill_stack_a(char **split_values, t_list **stack_a)
{
	int	word_index;
	int	num;

	word_index = 0;
	while (split_values[word_index] != NULL)
	{
		ft_atoi(split_values[word_index], &num);
		lst_add_back(stack_a, num);
		word_index++;
	}
}

int	check_duplicates(char **split_values)
{
	if (ft_duplicate(split_values) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
