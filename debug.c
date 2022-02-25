/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:22:53 by areggie           #+#    #+#             */
/*   Updated: 2022/02/25 18:02:43 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printing_array( t_metaljacket *arr)
{
	int	i;

	i = 0;
	while (i != arr->jacketlength)
	{
		printf("%d ", arr->metaljacket[i].bullet_value);
		i++;
	}
	printf("\n");
}

void debug_rotating(t_toolbox *tools)
{
	printing_array(&tools->a);
	rotating(tools, &tools->a);
	printing_array(&tools->a);
}

void debug_pushing(t_toolbox *tools)
{
	printing_array(&tools->a);
	pushing(&tools->b, &tools->a);
	printing_array(&tools->b);
	printing_array(&tools->a);
}

void debug_swapping(t_toolbox *tools)
{
	printing_array(&tools->a);
	swapping(tools, &tools->a);
	printing_array(&tools->a);
}

void debug_rev_rotating(t_toolbox *tools)
{
	printing_array(&tools->a);
	rev_rotate(&tools->a);
	printing_array(&tools->a);
}