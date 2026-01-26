/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:11:03 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/18 00:22:29 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_radix_bit(t_stack *stack_a, t_stack *stack_b, int bit,
		int size)
{
	int	j;
	int	b;

	j = 0;
	while (j < size)
	{
		b = (stack_a->top->index >> bit) & 1;
		if (b == 0)
		{
			pa_b(stack_b, stack_a);
			ft_printf("pb\n");
		}
		else
		{
			ra_b(stack_a);
			ft_printf("ra\n");
		}
		j++;
	}
	while (stack_b->size > 0)
	{
		pa_b(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

int	ft_radix(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_bits;
	int	size;

	max_bits = ft_maxbits(stack_a);
	i = 0;
	size = stack_a->size;
	while (i < max_bits)
	{
		process_radix_bit(stack_a, stack_b, i, size);
		i++;
	}
	return (1);
}

int	ft_maxbits(t_stack *stack_a)
{
	int	max;
	int	bits;

	max = stack_a->size - 1;
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}
