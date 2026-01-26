/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:43:18 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/26 08:58:01 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	compare_dup(long *nums, int total_count)
{
	int	i;
	int	p;

	i = 0;
	while (i < total_count)
	{
		p = i + 1;
		while (p < total_count)
		{
			if (nums[i] == nums[p])
				return (0);
			p++;
		}
		i++;
	}
	return (1);
}

int	ft_count_args(char **argv)
{
	int		i;
	int		total_count;
	int		j;
	char	**strings;

	i = 1;
	total_count = 0;
	while (argv[i])
	{
		strings = ft_split(argv[i], ' ');
		j = 0;
		while (strings[j])
		{
			free(strings[j]);
			j++;
		}
		free(strings);
		total_count = total_count + j;
		i++;
	}
	return (total_count);
}

char	**ft_copy_args(char **new_strings, char **argv)
{
	int		i;
	int		k;
	int		j;
	char	**strings;

	if (!new_strings || !argv)
		return (NULL);
	k = 0;
	i = 1;
	while (argv[i])
	{
		strings = ft_split(argv[i], ' ');
		if (!strings)
			return (NULL);
		j = 0;
		while (strings[j])
			new_strings[k++] = strings[j++];
		free(strings);
		i++;
	}
	new_strings[k] = NULL;
	return (new_strings);
}
