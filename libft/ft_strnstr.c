/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:30:31 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:35:45 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] && (i
				+ j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

//   #include <stdio.h>
// #include <string.h>
// #include <stddef.h>
//   int main(void)
// {
//     // Take any two strings
//     char s1[] = "holasdfg";
//     char s2[] = "asd";
//     size_t n = 15;
//     char* p;

//     // Find first occurrence of s2 in s1
//     p = ft_strnstr(s1, s2, n);

//     // Prints the result
//     if (p) {
//         printf("String found\n");
//         printf("First occurrence of string '%s' in '%s' is "
//                "'%s'",
//                s2, s1, p);
//     }
//     else
//         printf("String not found\n");

//     return (0);
// }