/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:06:48 by areggie           #+#    #+#             */
/*   Updated: 2022/02/27 21:07:35 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_or_not(t_toolbox *tools)
{
	int	i;

	i = 0;
	while (i != tools->argv_num - 1)
	{
		if (!(tools->array_for_sorting[i] < tools->array_for_sorting[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	init_stack_b_len(t_toolbox *tools)
{
	tools->b.metaljacket = malloc(sizeof(t_bullet) * tools->argv_num);
	if (!tools->array_for_sorting)
		error1();
	tools->b.jacketlength = 0;
}
