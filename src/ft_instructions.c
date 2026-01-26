/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:25:24 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/18 00:32:12 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa_b(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	node1 = stack->top;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = stack->top;
	stack->top = node2;
	return (1);
}

int	pa_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;
	t_node	*tmp;

	if (!stack_b || !stack_b->top)
		return (0);
	node_b = stack_b->top;
	tmp = node_b->next;
	node_b->next = stack_a->top;
	stack_a->top = node_b;
	stack_b->top = tmp;
	stack_a->size++;
	stack_b->size--;
	return (1);
}

int	ra_b(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	executed;

	executed = 0;
	if (stack_a && stack_a->top && stack_a->top->next)
	{
		ra_b(stack_a);
		executed = 1;
	}
	if (stack_b && stack_b->top && stack_b->top->next)
	{
		ra_b(stack_b);
		executed = 1;
	}
	return (executed);
}

int	rra_b(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}
