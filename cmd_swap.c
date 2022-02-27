/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:56:54 by areggie           #+#    #+#             */
/*   Updated: 2022/02/27 20:54:03 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping(t_toolbox *tools, t_metaljacket *metaljacket)
{			
	t_bullet	bullet_pocket;

	if (tools->argv_num > 1)
	{
		bullet_pocket = metaljacket->metaljacket[1];
		metaljacket->metaljacket[1] = metaljacket->metaljacket[0];
		metaljacket->metaljacket[0] = bullet_pocket;
	}
}

void	sa(t_toolbox *tools)
{
	swapping(tools, &tools->a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_toolbox *tools)
{
	swapping(tools, &tools->b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_toolbox *tools)
{
	swapping(tools, &tools->a);
	swapping(tools, &tools->b);
	ft_putstr_fd("ss\n", 1);
}
