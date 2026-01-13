/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:40:29 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/13 13:40:49 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	long			content;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* utils */
t_node	*ft_lstnew_p(long value);
void	push_top(t_stack *stack, t_node *node);
void	init_stack(t_stack *stack);

/* build stack */
void	lst_creator(t_stack *stack, long *nums, int total_count);

#endif
