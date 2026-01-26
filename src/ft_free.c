/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:08:31 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/21 14:12:11 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_error(void)
{
	write(2, "Error\n", 6);
	return ;
}

void	ft_stack_clear(t_stack *a, t_stack *b)
{
	t_stack	*stacks[2];
	t_node	*current;
	t_node	*tmp;
	int		i;

	stacks[0] = a;
	stacks[1] = b;
	i = 0;
	while (i < 2)
	{
		current = stacks[i]->top;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		stacks[i]->top = NULL;
		stacks[i]->size = 0;
		i++;
	}
}

int	ft_error_free_str(char **strings)
{
	int	i;

	if (!strings)
		return (0);
	ft_handle_error();
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (0);
}
