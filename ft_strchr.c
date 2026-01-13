/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:17:25 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:21:47 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;

	target = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <stddef.h>
// #include <string.h>
// int main (void)
// {
//     const char *s = "holasdfg";
//     int c = 97;
//     printf("FT:%s\n", ft_strchr(s, c));
//     printf("AA:%s\n", strchr(s, c));
//     return (0);
// }