/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:37:54 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/17 23:36:37 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_creator(t_stack *stack_a, long *nums, int total_count)
{
	t_node	*node;

	total_count--;
	while (total_count >= 0)
	{
		node = ft_lstnew_p(nums[total_count]);
		if (!node)
		{
			free_nodes(stack_a->top, stack_a);
			return ;
		}
		push_top(stack_a, node);
		total_count--;
	}
	index_stack(stack_a);
}

void	index_stack(t_stack *stack_a)
{
	t_node	*ptr_top;
	int		i;
	int		size;
	long	*arr;

	size = stack_a->size;
	arr = malloc(size * sizeof(long));
	if (!arr)
		return ;
	i = 0;
	ptr_top = stack_a->top;
	while (i < size)
	{
		arr[i] = ptr_top->content;
		ptr_top = ptr_top->next;
		i++;
	}
	ft_sort_array(arr, size);
	ft_assign_index(stack_a, arr, size);
}

void	ft_sort_array(long *arr, int size)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_assign_index(t_stack *stack_a, long *arr, int size)
{
	t_node	*ptr_top;
	int		i;

	ptr_top = stack_a->top;
	while (ptr_top)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == ptr_top->content)
			{
				ptr_top->index = i;
				break ;
			}
			i++;
		}
		ptr_top = ptr_top->next;
	}
	free(arr);
}
