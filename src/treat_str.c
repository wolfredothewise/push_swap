/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:43:18 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/01/13 14:25:33 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_handle_error(void)
{
	write(2, "Error\n", 6);
	return ;
}

void	ft_free_all_chars(char **strings)
{
	int	i;

	if (!strings)
		return ;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

int	ft_count_args(char **argv)
{
	int	i;
	int	total_count;
	int	j;
	char **strings;

	i = 1;
	total_count = 0;
	while (argv[i])
	{
		strings = ft_split(argv[i], ' ');
		j = 0;
		while (strings[j])
		{
			free(strings[j]);
			j++;
		}
		free(strings);
		total_count = total_count + j; // cuenta y libera el array temporal
		i++;
	}
	return (total_count);
}

char	**ft_copy_args(char **new_strings, char **argv)
{
	int i;
	int k;
	int j;
	char **strings;

	k = 0; // índice global de new_strings
	i = 1; // reiniciamos argv
	while (argv[i])
	{
		strings = ft_split(argv[i], ' ');
		j = 0;
		while (strings[j])
		{
			new_strings[k] = strings[j]; // apuntamos al mismo char *
			k++;
			j++;
		}
		free(strings);
		// liberamos solo el doble array y los args se quedan sueltos pero son apuntados por new_strings
		i++;
	}

	new_strings[k] = NULL;
	return (new_strings);
}