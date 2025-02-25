/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:29:55 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:48 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	element;

	element = lst_size(*stack_a);
	if (element == 2)
		swap(stack_a, "sa\n");
	else if (element == 3)
		sort_three_element(stack_a);
	else if (element == 5 || element == 4)
		sort_element(stack_a);
	else if (element > 5)
		sort_large_stack(stack_a, stack_b);
}

void	sort_three_element(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && first > third)
		rotate(stack_a, "ra\n");
	else if (second > first && second > third)
		reverse_rotate(stack_a, "rra\n");
	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	if (first > second)
		swap(stack_a, "sa\n");
}

static int	find_min_pos(t_list *stack)
{
	int	min_value;
	int	min_position;
	int	current_pos;

	min_value = stack->data;
	min_position = 0;
	current_pos = 0;
	while (stack != NULL)
	{
		if (stack->data < min_value)
		{
			min_value = stack->data;
			min_position = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_position);
}

static void	move_min_to_b(t_list **stack_a, t_list **stack_b, int *size)
{
	int	min_pos;

	min_pos = find_min_pos(*stack_a);
	while (min_pos != 0)
	{
		if (min_pos <= *size / 2)
		{
			rotate(stack_a, "ra\n");
			min_pos--;
		}
		else
		{
			reverse_rotate(stack_a, "rra\n");
			min_pos++;
			if (min_pos == *size)
				min_pos = 0;
		}
	}
	push_b(stack_a, stack_b);
	(*size)--;
}

void	sort_element(t_list **stack_a)
{
	t_list	*stack_b;
	int		size;

	stack_b = NULL;
	size = lst_size(*stack_a);
	while (size > 3)
	{
		move_min_to_b(stack_a, &stack_b, &size);
	}
	sort_three_element(stack_a);
	push_a(stack_a, &stack_b);
	push_a(stack_a, &stack_b);
}
