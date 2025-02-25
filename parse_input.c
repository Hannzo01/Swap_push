/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:29:40 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/24 17:34:30 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if (ft_flag(str[i]) == 0)
			return (0);
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		while (str[i][j] != '\0')
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
	return (1);
}

bool	ft_atoi(char *str, int *total)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == -1 && res > (long)INT_MAX + 1) || (sign == 1
				&& res > INT_MAX))
			return (false);
		i++;
	}
	*total = res * sign;
	return (true);
}

static bool	has_duplicates(int *arr, int size)
{
	int	j;
	int	k;

	j = 0;
	while (j < size - 1)
	{
		k = j + 1;
		while (k < size)
		{
			if (arr[k] == arr[j])
				return (true);
			k++;
		}
		j++;
	}
	return (false);
}

int	ft_duplicate(char **str)
{
	int	i;
	int	*arr;

	i = 0;
	arr = NULL;
	while (str[i] != NULL)
		i++;
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (0);
	i = 0;
	while (str[i] != NULL)
	{
		if (ft_atoi(str[i], &arr[i]) == false)
			return (free(arr), 0);
		i++;
	}
	if (has_duplicates(arr, i) == true)
	{
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}
