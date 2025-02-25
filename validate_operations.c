/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:33:03 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:36:38 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	validate_operation(t_list **stack_a, t_list **stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (check_validity(op, stack_a, stack_b) == 1)
		{
			free(get_next_line(-1));
			free(op);
			return (1);
		}
		free(op);
		op = get_next_line(0);
	}
	return (0);
}

int	check_validity(char *op, t_list **stack_a, t_list **stack_b)
{
	if (operations(op, stack_a, stack_b) == 1)
	{
		free_stacks(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	operations(char *op, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(op, "ra\n", 3) == 0)
		return (rotate(stack_a), 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		return (rotate(stack_b), 0);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		return (swap(stack_a), 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		return (swap(stack_b), 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		return (push_b(stack_a, stack_b), 0);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		return (push_a(stack_a, stack_b), 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		return (reverse_rotate(stack_a), 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		return (reverse_rotate(stack_b), 0);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		return (rr(stack_a, stack_b), 0);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		return (rrr(stack_a, stack_b), 0);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		return (ss(stack_a, stack_a), 0);
	else
		return (write(2, "Error\n", 6), 1);
}
