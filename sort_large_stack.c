/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:44:30 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:42:50 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	push_stack_b(stack_a, stack_b);
	sort_three_element(stack_a);
	while (lst_size(*stack_b) > 0)
	{
		fit_target(stack_a, stack_b);
		find_target_pos(stack_a, stack_b);
		update_pos_in_stack_b(stack_b);
		calculate_cost(stack_a, stack_b);
		cheapest_node = find_cheapest_move(stack_b);
		right_position(stack_a, stack_b, cheapest_node);
		push_a(stack_a, stack_b);
	}
	rotate_to_min(stack_a);
}
