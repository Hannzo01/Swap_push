/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:29:24 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 14:34:58 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (parse_args(argc, argv, &stack_a) == 1)
	{
		free_list(&stack_a);
		return (1);
	}
	if (validate_operation(&stack_a, &stack_b) == 1)
	{
		free_stacks(&stack_a, &stack_a);
		return (1);
	}
	if (is_sorted(&stack_a) == 0)
		return (write(2, "KO\n", 3), free_stacks(&stack_a, &stack_b), 0);
	else
		write(2, "OK\n", 3);
	return (free_stacks(&stack_a, &stack_b), 0);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
}
