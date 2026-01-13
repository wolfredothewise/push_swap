/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:59:14 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/12 11:24:07 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	copy;

	d_len = 0;
	s_len = 0;
	i = 0;
	while (src[s_len] != '\0')
		s_len++;
	while (dest[d_len] != '\0' && d_len < size)
		d_len++;
	if (d_len == size)
		return (size + s_len);
	copy = size - d_len - 1;
	while (i < copy && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>

// int main (void)
// {
//     char dest[8] = "Hola";
//     char *src = " Mundoooooooooooooooo";
//     printf("%zu", ft_strlcat(dest, src, sizeof(dest)));
//     return (0);

// }
