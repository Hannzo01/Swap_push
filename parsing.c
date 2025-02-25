/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:45:24 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:43:57 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int argc, char *argv[], t_list **stack_a)
{
	char	**split_values;
	int		count_args;

	count_args = count_args_and_check_empty(argc, argv);
	if (count_args == -1)
		return (1);
	if (allocate_and_initialize_split_values(&split_values, count_args) == 1)
		return (1);
	if (split_and_validate_args(argc, argv, split_values) == 1)
	{
		free_2d_arr(split_values);
		return (1);
	}
	if (check_duplicates(split_values) == 1)
	{
		free_2d_arr(split_values);
		return (1);
	}
	fill_stack_a(split_values, stack_a);
	free_2d_arr(split_values);
	return (0);
}

int	count_args_and_check_empty(int argc, char *argv[])
{
	int	i;
	int	count_args;

	i = 1;
	count_args = 0;
	while (i < argc)
	{
		count_args += count_words(argv[i]);
		if (empty_string(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (count_args);
}

int	allocate_and_initialize_split_values(char ***split_values, int count_args)
{
	int	j;

	*split_values = malloc(sizeof(char *) * (count_args + 1));
	if (!*split_values)
		return (1);
	j = 0;
	while (j < count_args + 1)
	{
		(*split_values)[j] = NULL;
		j++;
	}
	return (0);
}

void	free_2d_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

int	empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}
