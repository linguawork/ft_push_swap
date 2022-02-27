/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:01:12 by areggie           #+#    #+#             */
/*   Updated: 2022/02/27 20:50:26 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_metaljacket *metjacket)
{
	int			iter;
	t_bullet	buf;

	iter = metjacket->jacketlength;
	if (metjacket->jacketlength > 1)
	{
		buf = metjacket->metaljacket[metjacket->jacketlength - 1];
		while (iter != 0)
		{
			metjacket->metaljacket[iter] = metjacket->metaljacket[iter - 1];
			iter--;
		}
		metjacket->metaljacket[0] = buf;
	}
}

void	rra(t_toolbox *tools)
{
	rev_rotate(&tools->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_toolbox *tools)
{
	rev_rotate(&tools->b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_toolbox *tools)
{
	rev_rotate(&tools->a);
	rev_rotate(&tools->b);
	ft_putstr_fd("rrr\n", 1);
}
