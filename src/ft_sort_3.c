/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 23:43:18 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/18 00:02:45 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	determine_sort_3_case(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->top;
	if (node->index < node->next->index
		&& node->next->index < node->next->next->index)
		return (0);
	if (node->index < node->next->index
		&& node->index < node->next->next->index)
		return (1);
	if (node->index > node->next->index
		&& node->index < node->next->next->index)
		return (2);
	if (node->index < node->next->index
		&& node->index > node->next->next->index)
		return (3);
	if (node->index > node->next->index
		&& node->next->index > node->next->next->index)
		return (4);
	if (node->index > node->next->index
		&& node->index > node->next->next->index)
		return (5);
	return (-1);
}

static void	execute_sort_3_part1(t_stack *stack_a, int case_id)
{
	if (case_id == 1)
	{
		rra_b(stack_a);
		sa_b(stack_a);
		ft_printf("rra\nsa\n");
	}
	else if (case_id == 2)
	{
		sa_b(stack_a);
		ft_printf("sa\n");
	}
	else if (case_id == 3)
	{
		rra_b(stack_a);
		ft_printf("rra\n");
	}
}

static void	execute_sort_3_part2(t_stack *stack_a, int case_id)
{
	if (case_id == 4)
	{
		sa_b(stack_a);
		rra_b(stack_a);
		ft_printf("sa\nrra\n");
	}
	else if (case_id == 5)
	{
		ra_b(stack_a);
		ft_printf("ra\n");
	}
}

static void	execute_sort_3_ops(t_stack *stack_a, int case_id)
{
	if (case_id >= 1 && case_id <= 3)
		execute_sort_3_part1(stack_a, case_id);
	else if (case_id >= 4 && case_id <= 5)
		execute_sort_3_part2(stack_a, case_id);
}

int	ft_sort_3(t_stack *stack_a)
{
	int	case_id;

	if (!stack_a || !stack_a->top || !stack_a->top->next
		|| !stack_a->top->next->next)
		return (0);
	case_id = determine_sort_3_case(stack_a);
	if (case_id == 0 || case_id == -1)
		return (1);
	execute_sort_3_ops(stack_a, case_id);
	return (1);
}
