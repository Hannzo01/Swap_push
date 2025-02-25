/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-I.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:01:37 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/17 20:11:21 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, "r");
	rotate(stack_b, "r\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_b, "rr");
	reverse_rotate(stack_a, "r\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, "s");
	swap(stack_b, "s\n");
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
