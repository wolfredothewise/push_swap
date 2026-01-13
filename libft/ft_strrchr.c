/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:04:05 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:23:35 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// #include <stddef.h>
// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     const char *s = "holasdfgaPETES";
//     int c = 97;

//     printf("FT:%s\n", ft_strrchr(s, c));
//     printf("OG:%s\n", strrchr(s, c));
//     return (0);
// }