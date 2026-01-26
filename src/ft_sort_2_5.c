/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:23:35 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/18 00:23:39 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_2(t_stack *stack_a)
{
	t_node	*node;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (0);
	node = stack_a->top;
	if (node->index > node->next->index)
	{
		sa_b(stack_a);
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

static void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	while (size > 3)
	{
		if (stack_a->top->index < 2)
		{
			pa_b(stack_b, stack_a);
			ft_printf("pb\n");
			size--;
		}
		else
		{
			ra_b(stack_a);
			ft_printf("ra\n");
		}
	}
}

static void	finish_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	ft_sort_3(stack_a);
	if (stack_b->top && stack_b->top->next
		&& stack_b->top->index < stack_b->top->next->index)
	{
		sa_b(stack_b);
		ft_printf("sb\n");
	}
	pa_b(stack_a, stack_b);
	ft_printf("pa\n");
	pa_b(stack_a, stack_b);
	ft_printf("pa\n");
}

int	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	finish_sort_5(stack_a, stack_b);
	return (1);
}
