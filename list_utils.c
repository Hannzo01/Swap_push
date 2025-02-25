/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:29:42 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:35 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int data)
{
	t_list	*head;

	head = NULL;
	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

void	lst_add_back(t_list **lst, int data)
{
	t_list	*current;
	t_list	*new_node;

	if (!lst)
		return ;
	current = *lst;
	new_node = lst_new(data);
	if (!new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	lst_add_front(t_list **lst, t_list *new_node)
{
	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	new_node->next = *lst;
	*lst = new_node;
}

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
