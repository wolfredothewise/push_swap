/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:05:08 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/26 08:58:29 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_numbers(char **strings, int total_count, long **out_nums)
{
	long	*nums;
	int		i;
	int		err;

	if (!strings || total_count <= 0)
		return (0);
	nums = malloc(total_count * sizeof(long));
	if (!nums)
		return (0);
	i = 0;
	while (i < total_count)
	{
		nums[i] = ft_atol(strings[i], &err);
		if (err)
		{
			free(nums);
			return (0);
		}
		i++;
	}
	*out_nums = nums;
	return (1);
}

int	ft_dup_checker(char **strings, int total_count, t_stack *a)
{
	long	*nums;

	if (!parse_numbers(strings, total_count, &nums))
		return (0);
	if (!compare_dup(nums, total_count))
	{
		free(nums);
		return (0);
	}
	stack_creator(a, nums, total_count);
	free(nums);
	return (1);
}

int	ft_digit_checker(char **strings)
{
	int	i;
	int	j;

	i = 0;
	while (strings[i])
	{
		j = 0;
		if (strings[i][0] == '+' || strings[i][0] == '-')
		{
			if (!(ft_isdigit(strings[i][1])))
				return (0);
			j++;
		}
		while (strings[i][j])
		{
			if (!(ft_isdigit(strings[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_valid(char **argv, t_stack *a)
{
	char	**new_strings;
	int		total_count;
	int		valid;
	int		i;

	total_count = ft_count_args(argv);
	new_strings = malloc((total_count + 1) * sizeof(char *));
	if (!new_strings)
		return (0);
	new_strings = ft_copy_args(new_strings, argv);
	valid = 1;
	if (!ft_digit_checker(new_strings))
		valid = ft_error_free_str(new_strings);
	else if (!ft_dup_checker(new_strings, total_count, a))
		valid = ft_error_free_str(new_strings);
	i = 0;
	while (valid && new_strings[i])
	{
		free(new_strings[i]);
		i++;
	}
	if (valid)
		free(new_strings);
	return (valid);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (!ft_is_valid(argv, &stack_a))
		return (0);
	if (stack_a.size <= 1 || ft_is_sorted(&stack_a))
	{
		ft_stack_clear(&stack_a, &stack_b);
		return (0);
	}
	if (stack_a.size == 2)
		ft_sort_2(&stack_a);
	else if (stack_a.size == 3)
		ft_sort_3(&stack_a);
	else if (stack_a.size <= 5)
		ft_sort_5(&stack_a, &stack_b);
	else
		ft_radix(&stack_a, &stack_b);
	ft_stack_clear(&stack_a, &stack_b);
	return (0);
}
