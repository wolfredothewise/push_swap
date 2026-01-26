/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:56:46 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:27:14 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char *s = "holast";
//     int c = 97; // 'a'
//     size_t n = 4;

//     // ft_memchr
//     char *res1 = ft_memchr(s, c, n);
//     if (res1)
//         printf("ft_memchr: %s\n", res1);
//     else
//         printf("ft_memchr: No encontrado\n");

//     // memchr
//     char *res2 = memchr(s, c, n);
//     if (res2)
//         printf("memchr:    %s\n", res2);
//     else
//         printf("memchr:    No encontrado\n");

//     return (0);
// }
