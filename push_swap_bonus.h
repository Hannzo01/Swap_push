/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:48:07 by kemzouri          #+#    #+#             */
/*   Updated: 2025/02/25 13:31:13 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "gnl/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

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
}					t_list;

//  PARSING FUNCTIONS //
char				**ft_split(char *str, char c);
char				*ft_strdup(char *s);
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

//  checker  //
int					validate_operation(t_list **stack_a, t_list **stack_b);
int					check_validity(char *op, t_list **stack_a,
						t_list **stack_b);
int					operations(char *op, t_list **stack_a, t_list **stack_b);

// functions //
int					empty_string(char *str);
void				free_2d_arr(char **arr);
int					ft_is_valid(char **str);
int					ft_flag(char *str);
bool				ft_atoi(char *str, int *total);
int					ft_strncmp(char *s1, char *s2, int n);

// LIST //
t_list				*lst_new(int data);
void				lst_add_back(t_list **lst, int data);
void				lst_add_front(t_list **lst, t_list *new_node);
t_list				*lst_last(t_list *lst);
int					is_sorted(t_list **stack_a);
t_list				*lst_second_to_last(t_list *lst);
void				free_list(t_list **stack_a);
int					lst_size(t_list *stack_a);

//	OPERATIONS  //
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
void				push_b(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);

#endif