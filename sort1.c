/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:57:05 by areggie           #+#    #+#             */
/*   Updated: 2022/03/02 12:57:35 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_toolbox *tools)
{
	if (tools->a.jacketlength == 2 && tools->a.metaljacket[0].bullet_value > \
		tools->a.metaljacket[1].bullet_value)
		sa(tools);
}

void	sort3_1(t_toolbox *tools)
{
	if (tools->a.metaljacket[0].bullet_value < \
	tools->a.metaljacket[1].bullet_value
		&& tools->a.metaljacket[1].bullet_value > \
		tools->a.metaljacket[2].bullet_value
		&& tools->a.metaljacket[0].bullet_value < \
		tools->a.metaljacket[2].bullet_value)
	{
		rra(tools);
		sa(tools);
	}
	if (tools->a.metaljacket[0].bullet_value > \
	tools->a.metaljacket[1].bullet_value
		&& tools->a.metaljacket[1].bullet_value > \
		tools->a.metaljacket[2].bullet_value)
	{
		sa(tools);
		rra(tools);
	}
	if (tools->a.metaljacket[0].bullet_value > \
	tools->a.metaljacket[1].bullet_value
		&& tools->a.metaljacket[1].bullet_value < \
		tools->a.metaljacket[2].bullet_value
		&& tools->a.metaljacket[0].bullet_value > \
		tools->a.metaljacket[2].bullet_value)
		ra(tools);
}

void	sort3_2(t_toolbox *tools)
{
	if (tools->a.metaljacket[0].bullet_value > \
	tools->a.metaljacket[1].bullet_value
		&& tools->a.metaljacket[1].bullet_value < \
		tools->a.metaljacket[2].bullet_value
		&& tools->a.metaljacket[0].bullet_value < \
		tools->a.metaljacket[2].bullet_value)
		sa(tools);
	if (tools->a.metaljacket[0].bullet_value < \
	tools->a.metaljacket[1].bullet_value
		&& tools->a.metaljacket[1].bullet_value > \
		tools->a.metaljacket[2].bullet_value
		&& tools->a.metaljacket[0].bullet_value > \
		tools->a.metaljacket[2].bullet_value)
		rra(tools);
}

void	sort3(t_toolbox *tools)
{
	if (tools->a.jacketlength == 3)
	{
		sort3_1(tools);
		sort3_2(tools);
	}
}
