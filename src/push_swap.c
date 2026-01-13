/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:05:08 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/13 14:37:13 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int ft_dup_checker(char **strings, int total_count, t_stack *a)
    {
        long *nums;
        int i;
        int p;
    
        if (!strings)
            return 0;
        nums = malloc(total_count * sizeof(long));
        if (!nums)
            return 0;
        // Convertir strings a long
        i = 0;
        while (i < total_count)
        {
            nums[i] = ft_atol(strings[i]);
            i++;
        }
        // Comparar duplicados
        i = 0;
        while (i < total_count)
        {
            p = i + 1;
            while (p < total_count)
            {
                if (nums[i] == nums[p])
                {
                    ft_handle_error();
                    free(nums);
                    return 0;
                }
                p++;
            }
            i++;
        }
        i = 0;
        stack_creator(a, nums, total_count);
        free(nums);
        return 1;
    }
 
int ft_digit_checker(char **strings)
    {
        int i;
        int j;

        i = 0;
        while (strings[i])
        {
            j = 0;
            
            if (strings[i][0] == '+' || strings[i][0] == '-') // + -
            {
                if (!(isdigit(strings[i][1]))) //Si el siguiente, no es digito-->error
                    {
                        ft_handle_error();
                        ft_free_all_chars(strings);
                        return 0;
                    }
                j++;
            }  
            while (strings[i][j])
            {                    

                if (!(isdigit(strings[i][j])))
                    {
                        ft_handle_error();
                        ft_free_all_chars(strings);
                        return 0;
                    }
                        j++;
            }
            i++;
        }   
        return (1);
    }
    
int ft_is_valid(char **argv, t_stack *a)
{
    char **new_strings;
    int i;
    int total_count;

//contar args-->funcion para contar args
total_count = ft_count_args(argv);

//buff para todos los args
    new_strings = malloc((total_count + 1) * sizeof(char *));
    if (!new_strings)
        return 0;  // fallo de malloc
    new_strings = ft_copy_args(new_strings,argv);//copiar args
    if (!ft_digit_checker(new_strings))
        return 0;
    if (!ft_dup_checker(new_strings, total_count, a))
        return 0;        
    return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!ft_is_valid(argv, &a))
		return (0);
	// aquí empiezan los algoritmos
	return (0);
}
