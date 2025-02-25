/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:07:11 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 13:56:00 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// HEADERS //
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // delete later
# include <stdlib.h>
# include <unistd.h>

// STRUCT //

typedef struct s_list
{
	int				data;
	int				rank;
	int				cost;
	int				pos;
	int				b_m;
	int				target_pos;
	struct s_list	*next;
	struct s_list	*target;
	// traversing stack_a just once for each element in stack_b.
}					t_list;

//  PARSING FUNCTIONS //

char				**ft_split(char *str, char c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(char *s);
void				ft_putstr(char *str);
void				free_2d_arr(char **arr);
int					empty_string(char *str);
int					ft_is_valid(char **str);
int					ft_flag(char *str);
int					ft_duplicate(char **str);
int					check_duplicates(char **split_values);
bool				ft_atoi(char *str, int *total);
int					parse_args(int argc, char *argv[], t_list **stack_a);
int					count_args_and_check_empty(int argc, char *argv[]);
int					count_words(char *str);
int					allocate_and_initialize_split_values(char ***split_values,
						int count_args);
int					split_and_validate_args(int argc, char *argv[],
						char **split_values);
void				fill_stack_a(char **split_values, t_list **stack_a);
void				free_stacks(t_list **stack_a, t_list **stack_b);

// SORTING //

void				sort_stack(t_list **stack_a, t_list **stack_b);
void				sort_three_element(t_list **stack_a);
void				sort_element(t_list **stack_a);
void				sort_large_stack(t_list **stack_a, t_list **stack_b);

// 	ALGO LARGE SORT   //

void				push_stack_b(t_list **stack_a, t_list **stack_b);
void				fit_target(t_list **stack_a, t_list **stack_b);
void				find_target_pos(t_list **stack_a, t_list **stack_b);
void				update_pos_in_stack_b(t_list **stack_b);
void				calculate_cost(t_list **stack_a, t_list **stack_b);
t_list				*find_cheapest_move(t_list **stack_b);
void				right_position(t_list **s_a, t_list **s_b,
						t_list *cheapest_node);
void				rotate_to_min(t_list **stack_a);

// OPERATIONS //

void				swap(t_list **stack, char *str);
void				rotate(t_list **stack, char *str);
void				reverse_rotate(t_list **stack, char *str);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);

// LIST //
t_list				*lst_new(int data);
void				lst_add_back(t_list **lst, int data);
void				lst_add_front(t_list **lst, t_list *new_node);
t_list				*lst_last(t_list *lst);
int					is_sorted(t_list **stack_a);
t_list				*lst_second_to_last(t_list *lst);
void				free_list(t_list **stack_a);
int					lst_size(t_list *stack_a);

#endif