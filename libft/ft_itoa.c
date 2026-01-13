/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:33:10 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/10/14 10:49:49 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nb;

	nb = n;
	len = (nb <= 0);
	while (nb && ++len)
		nb = nb / 10;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	nb = n;
	if (nb < 0)
		nb = nb * -1;
	if (nb == 0)
		s[0] = '0';
	while (nb)
	{
		s[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}

// len = 1 if n<=0 es como un if acortado LINEA 22