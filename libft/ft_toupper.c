/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:10:03 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:18:58 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%c\n", ft_toupper('a')); // A
// 	printf("%c\n", ft_toupper('B')); // B
// 	printf("%c\n", ft_toupper('1')); // 1
// }