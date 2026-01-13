/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:55:26 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/15 14:26:09 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	void				*ret;

	if (!to && !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)to;
	ret = to;
	while (n > 0)
	{
		*d = *s;
		n--;
		s++;
		d++;
	}
	return (ret);
}
// int main (void)
// {
//     char to[5];
//     char src[]= "Holaaaa";
//     size_t n = 4;
//     ft_memcpy(to, src, n);
// printf("%s\n", to);
// return (0);
// }