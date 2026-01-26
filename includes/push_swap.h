/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:40:29 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/21 14:12:03 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ================= INCLUDES ================= */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ================= STRUCTS ================= */

typedef struct s_node
{
	long			content;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* ================= INIT / STACK ================= */

void				init_stack(t_stack *stack);
void				push_top(t_stack *stack, t_node *node);

/* ================= PARSING / CHECKERS ================= */

int					ft_is_valid(char **argv, t_stack *a);
int					ft_digit_checker(char **strings);
int					ft_dup_checker(char **strings, int total_count, t_stack *a);
int					ft_count_args(char **argv);
char				**ft_copy_args(char **new_strings, char **argv);
int					compare_dup(long *nums, int total_count);
int					ft_is_sorted(t_stack *stack);

/* ================= ERROR ================= */

void				ft_handle_error(void);
int					ft_error_free_str(char **strings);
void				ft_stack_clear(t_stack *a, t_stack *b);

/* ================= CREATE STACK + INDEX ================= */

void				stack_creator(t_stack *stack_a, long *nums,
						int total_count);
void				free_nodes(t_node *node, t_stack *stack_a);

/* index helpers */
void				index_stack(t_stack *stack_a);
void				ft_sort_array(long *arr, int size);
void				ft_assign_index(t_stack *stack_a, long *arr, int size);

/* ================= SORT ================= */

int					ft_sort_2(t_stack *stack_a);
int					ft_sort_3(t_stack *stack_a);
int					ft_sort_5(t_stack *stack_a, t_stack *stack_b);
int					ft_radix(t_stack *stack_a, t_stack *stack_b);
int					ft_maxbits(t_stack *stack_a);

/* ================= INSTRUCTIONS ================= */

/* swap */
int					sa_b(t_stack *stack);
/* push */
int					pa_b(t_stack *stack_a, t_stack *stack_b);

/* rotate */
int					ra_b(t_stack *stack);
int					rr(t_stack *stack_a, t_stack *stack_b);

/* reverse rotate */
int					rra_b(t_stack *stack);

/* ================= LIBFT (USED) ================= */

long				ft_atol(const char *str, int *error);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
int					ft_printf(const char *str, ...);
t_node				*ft_lstnew_p(long value);

#endif
