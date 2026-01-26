/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:46:49 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:20:50 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	c1 = 'A';
// 	char	c2 = 'z';
// 	char	c3 = '5';

// 	printf("%c -> %c\n", c1, ft_tolower(c1));
// 	printf("%c -> %c\n", c2, ft_tolower(c2));
// 	printf("%c -> %c\n", c3, ft_tolower(c3));
// 	return (0);
// }