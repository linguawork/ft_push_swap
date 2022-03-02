/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:14:53 by areggie           #+#    #+#             */
/*   Updated: 2022/03/02 12:29:08 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_borderline(t_toolbox *tools)
{
	int	borderline;

	if (tools->argv_num <= 100)
		borderline = 15;
	else
		borderline = 30;
	return (borderline);
}

int	define_max_index(t_metaljacket mj)
{
	int	i;
	int	max_mark;

	i = 0;
	max_mark = mj.metaljacket[i].bullet_index;
	while (i < mj.jacketlength)
	{
		if (mj.metaljacket[i].bullet_index > max_mark)
			max_mark = mj.metaljacket[i].bullet_index;
		i++;
	}
	return (max_mark);
}

void	compare_max_and_pa(t_toolbox *tools)
{
	int	idx;
	int	max_idx;

	while (tools->b.jacketlength > 0)
	{
		max_idx = define_max_index(tools->b);
		idx = tools->b.metaljacket[0].bullet_index;
		if (idx != max_idx && !compare_before_after_median(tools->b, max_idx))
			rb(tools);
		else if (idx != max_idx && \
		compare_before_after_median(tools->b, max_idx))
			rrb(tools);
		else if (idx == max_idx)
			pa(tools);
	}
}

void	sortmore(t_toolbox *tools)
{
	int	i;
	int	borderline;
	int	index;

	i = 0;
	borderline = set_borderline(tools);
	while (tools->a.jacketlength > 0)
	{
		index = tools->a.metaljacket[0].bullet_index;
		if (i > 1 && index <= i)
		{
			pb(tools);
			rb(tools);
			i++;
		}
		else if (index <= i + borderline)
		{
			pb(tools);
			i++;
		}
		else if (index >= i)
			ra(tools);
	}
	compare_max_and_pa(tools);
}
