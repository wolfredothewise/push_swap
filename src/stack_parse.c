/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:54:44 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/13 14:30:17 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}


void push_top(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return;
    node->next = stack->top;  // el nodo apunta al top
    stack->top = node;       // ahora el nodo es el nuevo top
    stack->size++;          //size se incrementa en 1
}

    void	stack_creator(t_stack *stack, long *nums, int total_count)
    {
    	t_node	*node;
    	int		i;
    
    
        int     j;
    
    	i = total_count - 1;
    	while (i >= 0)
    	{
    		node = ft_lstnew_p(nums[i]);
    		if (!node)
    			return; // en proyecto real → free + error
    		push_top(stack, node);
    		i--;
    	}
        	index_stack(stack);    
    }
void index_stack(t_stack *stack)


    // i = 0;
    // while(nums[i])
    // {
    //     j = 0;
    //     while (nums[j])
    //     {
    //         if(nums[i] >  nums[j])
    //         {
    //             tmp = nums[i];
    //             nums[i] = nums[j];
    //             nums[j] = tmp;
    //         }
    //         j++;
    //     }
    //     i++;
    // }
    // i = 0;
    // while(total_count > 0)
    // {
    //     if(nums[i] == stack_a.top)
    //     {
    //         node->index == i;
    //     }
    // total_count--;
    // i++;
    // }












