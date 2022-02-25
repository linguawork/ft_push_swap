/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:00:37 by areggie           #+#    #+#             */
/*   Updated: 2022/02/23 18:25:25 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotating(t_toolbox *tools, t_metaljacket *metjacket)
{
	int	iter;
	t_bullet buf;
	
	iter = 0;
	if (tools->argv_num > 1)
	{
		buf = metjacket->metaljacket[0];// иерархия магазин ->ячейка в магазине (т.е пуля)
		while(iter != metjacket->jacketlength - 1)// (дебаг)убираем терм ноль
		{
			metjacket->metaljacket[iter] = metjacket->metaljacket[iter + 1];
			iter++;
		}
		metjacket->metaljacket[iter] = buf; // первую ячейку в конец
	}
}

void ra(t_toolbox *tools)
{
	rotating(tools, &tools->a);// подаем количество и сам магазин
	ft_putstr_fd("ra\n", 1);
}

void rb(t_toolbox *tools)
{
	rotating(tools, &tools->b);// подаем количество и сам магазин
	ft_putstr_fd("rb\n", 1);
}

void rr(t_toolbox *tools)
{
	rotating(tools, &tools->a);
	rotating(tools, &tools->b);
	ft_putstr_fd("rr\n", 1);
}