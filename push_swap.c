/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:37:25 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 14:29:15 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (is_sorted(&stack_a) == 1)
	{
		free_list(&stack_a);
		return (1);
	}
	sort_stack(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
}
