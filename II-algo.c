/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   II-algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:34:04 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/24 11:00:21 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;
	int		target_pos;

	current_b = *stack_b;
	while (current_b != NULL)
	{
		current_a = *stack_a;
		target_pos = 0;
		while (current_a != NULL)
		{
			if (current_b->target == current_a)
			{
				current_b->target_pos = target_pos;
				break ;
			}
			target_pos++;
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}

void	update_pos_in_stack_b(t_list **stack_b)
{
	t_list	*current_b;
	int		pos;

	current_b = *stack_b;
	pos = 0;
	while (current_b != NULL)
	{
		current_b->pos = pos;
		current_b = current_b->next;
		pos++;
	}
}

static void	cal_pos(t_list *current_b, int size, int *cost_pos)
{
	if (current_b->pos <= size / 2)
		*cost_pos = current_b->pos;
	else
		*cost_pos = size - current_b->pos;
}

static void	cal_pos_target(t_list *current_b, int size, int *cost_target_pos)
{
	if (current_b->target_pos <= size / 2)
		*cost_target_pos = current_b->target_pos;
	else
		*cost_target_pos = size - current_b->target_pos;
}

void	calculate_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	int		s_a;
	int		s_b;
	int		cost_pos;
	int		cost_target_pos;

	s_a = lst_size(*stack_a);
	s_b = lst_size(*stack_b);
	current_b = *stack_b;
	while (current_b)
	{
		cal_pos(current_b, s_b, &cost_pos);
		cal_pos_target(current_b, s_a, &cost_target_pos);
		if ((current_b->pos <= s_b / 2 && current_b->target_pos <= s_a / 2)
			|| (current_b->pos > s_b / 2 && current_b->target_pos > s_a / 2))
		{
			if (cost_pos > cost_target_pos)
				current_b->cost = cost_pos;
			else
				current_b->cost = cost_target_pos;
		}
		else
			current_b->cost = cost_pos + cost_target_pos;
		current_b = current_b->next;
	}
}
