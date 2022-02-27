/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5moreops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:06:53 by areggie           #+#    #+#             */
/*   Updated: 2022/02/27 21:23:08 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value_to_top5(t_toolbox *tools)
{
	int	i;

	i = 0;
	while (i != tools->argv_num)
	{
		if (tools->a.metaljacket[0].bullet_value < \
		tools->a.metaljacket[1].bullet_value
			&& tools->a.metaljacket[0].bullet_value < \
			tools->a.metaljacket[2].bullet_value
			&& tools->a.metaljacket[0].bullet_value < \
			tools->a.metaljacket[3].bullet_value
			&& tools->a.metaljacket[0].bullet_value < \
			tools->a.metaljacket[4].bullet_value)
			return (0);
		ra(tools);
	}
	return (1);
}

void	sort5(t_toolbox *tools)
{
	if (tools->a.jacketlength == 5)
	{
		min_value_to_top5(tools);
		pb(tools);
		min_value_to_top4(tools);
		pb(tools);
		tools->a.jacketlength = 3;
		sort3(tools);
		pa(tools);
		pa(tools);
	}
}
