/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:54:44 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/17 23:31:04 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_node *node, t_stack *stack_a)
{
	t_node	*tmp;

	ft_handle_error();
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	init_stack(stack_a);
}

t_node	*ft_lstnew_p(long value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = -1;
	node->next = (NULL);
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	push_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}
