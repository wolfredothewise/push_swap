/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:06:37 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/14 11:55:12 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
// #include <stdio.h>
// int main (void)
// {
//     char str[6] = "hola!";
//     int n = 1;
//     ft_bzero(str + 2, n);
//     printf("%s",str);
//     return (0);
// }
