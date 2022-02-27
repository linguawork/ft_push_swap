/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:16:29 by areggie           #+#    #+#             */
/*   Updated: 2022/02/27 21:07:18 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort_array(t_toolbox *tools)
{
	int	i;
	int	tmp;
	int	k;

	i = 0;
	while (i < tools->argv_num)
	{
		k = i;
		while (k > 0 && tools->array_for_sorting[k - 1] > \
		tools->array_for_sorting[k])
		{
			tmp = tools->array_for_sorting[k - 1];
			tools->array_for_sorting[k - 1] = tools->array_for_sorting[k];
			tools->array_for_sorting[k] = tmp;
			k -= 1;
		}
		i++;
	}
}

//return index of the sorted array that matches a number in the given array 
int	match_index_to_number(int *sorted_array, int metaljacket_bullet)
{
	int	i;

	i = 0;
	while (sorted_array[i] != metaljacket_bullet)
			i++;
	return (i);
}

void	record_indexes_into_metaljacket(t_toolbox *tools)
{
	int	i;

	i = 0;
	while (i != tools->argv_num)
	{
		tools->a.metaljacket[i].bullet_index = \
		match_index_to_number(tools->array_for_sorting, \
		tools->a.metaljacket[i].bullet_value);
		i++;
	}
}

void	sorting(t_toolbox *tools)
{	
	sort2(tools);
	sort3(tools);
	sort4(tools);
	insertion_sort_array(tools);
	record_indexes_into_metaljacket(tools);
	if (tools->a.jacketlength == 5)
		sort5_(tools);
	else if (tools->a.jacketlength > 5)
		sortmore(tools);
}

int	main(int argc, char **argv)
{
	t_toolbox	*tools;

	tools = malloc(sizeof(t_toolbox));
	tools->argv_num = argv_counter(argv) - 1;
	validate_a_and_charge_metaljacket(argc, argv, tools);
	if (!check_sorted_or_not(tools))
	{
		init_stack_b_len(tools);
		sorting(tools);
	}
	exit(EXIT_SUCCESS);
}
