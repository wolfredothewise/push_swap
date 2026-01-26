/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:59:29 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/17 23:28:47 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_help_atol(long result, long sign, int *error)
{
	if (result * sign > INT_MAX || result * sign < INT_MIN)
	{
		*error = 1;
		return (0);
	}
	return (result * sign);
}

long	ft_atol(const char *nptr, int *error)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = sign * -1;
		i = i + 1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (ft_help_atol(result, sign, error));
}
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *nptr;

// 	nptr = " +123";
// 	printf("FT:%d\n", ft_atol(nptr));
// 	printf("ATOI:%d\n", atoi(nptr));
// 	return (0);
// }