/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I-algo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:34:00 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:08 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ranking(t_list **stack_a)
{
	t_list	*current_element;
	t_list	*head;
	int		counter;

	current_element = *stack_a;
	while (current_element != NULL)
	{
		counter = 0;
		head = *stack_a;
		while (head != NULL)
		{
			if (current_element->data > head->data)
				counter++;
			head = head->next;
		}
		current_element->rank = counter;
		current_element = current_element->next;
	}
}

void	push_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	middle;

	size = lst_size(*stack_a);
	while (size > 3)
	{
		ranking(stack_a);
		middle = size / 2;
		if ((*stack_a)->rank <= middle)
			push_b(stack_a, stack_b);
		else
			rotate(stack_a, "ra\n");
		size = lst_size(*stack_a);
	}
}

static t_list	*find_smallest_node(t_list *stack_a)
{
	t_list	*curr_a;
	t_list	*smallest;
	int		a_min;

	smallest = NULL;
	curr_a = stack_a;
	a_min = INT_MAX;
	while (curr_a)
	{
		if (curr_a->data < a_min)
		{
			a_min = curr_a->data;
			smallest = curr_a;
		}
		curr_a = curr_a->next;
	}
	return (smallest);
}

static t_list	*find_target_for_node(t_list *stack_a, int b_data,
		t_list *a_min)
{
	t_list	*curr_a;
	t_list	*target;
	int		destination;

	curr_a = stack_a;
	target = NULL;
	destination = INT_MAX;
	while (curr_a)
	{
		if (curr_a->data > b_data && curr_a->data < destination)
		{
			destination = curr_a->data;
			target = curr_a;
		}
		curr_a = curr_a->next;
	}
	if (target == NULL)
		target = a_min;
	return (target);
}

void	fit_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_min_node;
	t_list	*curr_b;

	curr_b = *stack_b;
	a_min_node = find_smallest_node(*stack_a);
	while (curr_b != NULL)
	{
		curr_b->target = find_target_for_node(*stack_a, curr_b->data,
				a_min_node);
		curr_b = curr_b->next;
	}
}
