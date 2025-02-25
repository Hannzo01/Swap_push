/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:45:12 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second_last = lst_second_to_last(*stack);
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	lst_add_front(stack_b, tmp);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	lst_add_front(stack_a, tmp);
}
