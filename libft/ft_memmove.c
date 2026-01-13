/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:11:01 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/13 15:11:44 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;
	size_t				i;

	d = dest;
	i = 0;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[50] = "Hola, mundo!";
//     char str2[50] = "Hola, mundo!";
//     char str3[50] = "1234567890";
//     char str4[50] = "1234567890";

//     // Caso 1: Copia normal (sin solapamiento)
//     printf("Caso 1 - Copia normal:\n");
//     ft_memmove(str1 + 7, str1, 5); // "Hola, mHola,"
//     printf("ft_memmove: %s\n", str1);

//     memmove(str2 + 7, str2, 5);
//     printf("memmove:    %s\n", str2);

//     // Caso 2: Copia con solapamiento hacia adelante
//     printf("\nCaso 2 - Solapamiento hacia adelante:\n");
//     ft_memmove(str3 + 2, str3, 8);
//     printf("ft_memmove: %s\n", str3);

//     memmove(str4 + 2, str4, 8);
//     printf("memmove:    %s\n", str4);

//     // Caso 3: Copia con solapamiento hacia atrás
//     printf("\nCaso 3 - Solapamiento hacia atrás:\n");
//     char str5[50] = "ABCDEFGHIJ";
//     char str6[50] = "ABCDEFGHIJ";

//     ft_memmove(str5, str5 + 2, 8); // Debería mover "CDEFGHIJ" a inicio
//     printf("ft_memmove: %s\n", str5);

//     memmove(str6, str6 + 2, 8);
//     printf("memmove:    %s\n", str6);

//     return (0);
// }
