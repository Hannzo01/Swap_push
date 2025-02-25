/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utlis2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:30:36 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 11:48:26 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_second_to_last(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	free_list(t_list **stack_a)
{
	t_list	*current;
	t_list	*tmp;

	if (!stack_a)
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack_a = NULL;
}

int	lst_size(t_list *stack_a)
{
	int	counter;

	counter = 0;
	while (stack_a != NULL)
	{
		counter++;
		stack_a = stack_a->next;
	}
	return (counter);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
