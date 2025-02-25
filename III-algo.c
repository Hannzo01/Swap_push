/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   III-algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:29:07 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:41:26 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest_move(t_list **stack_b)
{
	t_list	*cheapest_node;
	int		cheapest_cost;
	t_list	*current_b;

	cheapest_node = *stack_b;
	cheapest_cost = cheapest_node->cost;
	current_b = (*stack_b)->next;
	while (current_b)
	{
		if (current_b->cost < cheapest_cost)
		{
			cheapest_cost = current_b->cost;
			cheapest_node = current_b;
		}
		else if (current_b->cost == cheapest_cost)
		{
			if (current_b->target_pos < cheapest_node->target_pos)
				cheapest_node = current_b;
		}
		current_b = current_b->next;
	}
	return (cheapest_node);
}

static void	find_b_m(t_list **stack, t_list *node)
{
	int		middle;
	int		pos;
	t_list	*current;

	middle = lst_size(*stack) / 2;
	pos = 0;
	current = *stack;
	while (current)
	{
		if (current == node)
		{
			if (pos <= middle)
				node->b_m = 0;
			else
				node->b_m = 1;
			break ;
		}
		pos++;
		current = current->next;
	}
}

void	right_position(t_list **s_a, t_list **s_b, t_list *cheapest_node)
{
	find_b_m(s_b, cheapest_node);
	find_b_m(s_a, cheapest_node->target);
	if (cheapest_node->b_m == 0 && cheapest_node->target->b_m == 0)
		while (cheapest_node != *s_b && cheapest_node->target != *s_a)
			rr(s_a, s_b);
	else if (cheapest_node->b_m == 1 && cheapest_node->target->b_m == 1)
	{
		while (cheapest_node != *s_b && cheapest_node->target != *s_a)
			rrr(s_a, s_b);
	}
	while (*s_b != cheapest_node)
	{
		if (cheapest_node->b_m == 0)
			rotate(s_b, "rb\n");
		else
			reverse_rotate(s_b, "rrb\n");
	}
	while (*s_a != cheapest_node->target)
	{
		if (cheapest_node->target->b_m == 0)
			rotate(s_a, "ra\n");
		else
			reverse_rotate(s_a, "rra\n");
	}
}

static int	find_min_position(t_list **stack_a)
{
	t_list	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = *stack_a;
	min = current->data;
	pos = 0;
	min_pos = 0;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_to_min(t_list **stack_a)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(stack_a);
	size = lst_size(*stack_a);
	while (min_pos != 0)
	{
		if (min_pos <= size / 2)
			rotate(stack_a, "ra\n");
		else
			reverse_rotate(stack_a, "rra\n");
		min_pos = find_min_position(stack_a);
	}
}
