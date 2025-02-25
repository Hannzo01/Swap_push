/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-II.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:56:19 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:43:49 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *str)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_putstr(str);
}

void	rotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack) || !stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr(str);
}

void	reverse_rotate(t_list **stack, char *str)
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
	ft_putstr(str);
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
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
}
