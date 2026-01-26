/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:59:35 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/17 23:19:23 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_node	*ft_lstnew(void *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = -1;
	node->next = (NULL);
	return (node);
}

// #include <stdio.h>
// int main(void)
// {
//     int num = 42;
//     t_list *nodo = ft_lstnew(&num);
//     printf("Valor: %d\n", *(int *)nodo->content);
//     free(nodo);
// }