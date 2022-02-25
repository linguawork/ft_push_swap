/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:57:05 by areggie           #+#    #+#             */
/*   Updated: 2022/02/25 21:28:07 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort2(t_toolbox *tools)
{
	if (tools->a.jacketlength == 2 && tools->a.metaljacket[0].bullet_value >
		tools->a.metaljacket[1].bullet_value)
	{
		sa(tools);
		// printing_array(&tools->a);
	}
}

void sort3_1(t_toolbox *tools)
{
	if (tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[1].bullet_value \
		&& tools->a.metaljacket[1].bullet_value > tools->a.metaljacket[2].bullet_value
		&& tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[2].bullet_value) //1 3 2
	{
		rra(tools);
		sa(tools);
		// printing_array(&tools->a);
	}
	
	if (tools->a.metaljacket[0].bullet_value > tools->a.metaljacket[1].bullet_value \
		&& tools->a.metaljacket[1].bullet_value > tools->a.metaljacket[2].bullet_value) //3 2 1
	{
		sa(tools);
		rra(tools);
		// printing_array(&tools->a);
	}
	if (tools->a.metaljacket[0].bullet_value > tools->a.metaljacket[1].bullet_value \
		&& tools->a.metaljacket[1].bullet_value < tools->a.metaljacket[2].bullet_value \
		&& tools->a.metaljacket[0].bullet_value > tools->a.metaljacket[2].bullet_value) //3 1 2
	{
		ra(tools);
		// printing_array(&tools->a);
	}
}

void sort3_2(t_toolbox *tools)
{
	if (tools->a.metaljacket[0].bullet_value > tools->a.metaljacket[1].bullet_value \
		&& tools->a.metaljacket[1].bullet_value < tools->a.metaljacket[2].bullet_value \
		&& tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[2].bullet_value) //2 1 3
	{
		sa(tools);
		// printing_array(&tools->a);
	}
	if (tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[1].bullet_value \
		&& tools->a.metaljacket[1].bullet_value > tools->a.metaljacket[2].bullet_value \
		&& tools->a.metaljacket[0].bullet_value > tools->a.metaljacket[2].bullet_value) //2 3 1
	{
		rra(tools);
		// printing_array(&tools->a);
	}	
}

void sort3(t_toolbox *tools)
{
	if (tools->a.jacketlength == 3)
	{ 	
		sort3_1(tools);
		sort3_2(tools);
	}
}

