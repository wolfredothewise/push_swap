/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:21:16 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/12 11:24:46 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *buffer, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			buffer[i] = src[i];
			i++;
		}
	}
	buffer[i] = '\0';
	return (len);
}
// #include <stdio.h>
// int main (void)
// {
//     char buffer[6];
//     char *src = "We";
//     printf("%zu\n", ft_strlcpy(buffer, src, sizeof(buffer)));
//     return (0);
// }
