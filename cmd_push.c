/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:49:28 by areggie           #+#    #+#             */
/*   Updated: 2022/02/25 21:18:18 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing(t_metaljacket *put_in, t_metaljacket *put_out)
{
	int bullet_val;

	
	// put_out->jacketlength = tools->argv_num; // важно сохранить длину по кол-ву аргументов
	//длину уже не привязывал к argv_num так как она меняется и сохраняется в структуру
	bullet_val = put_in->jacketlength + 1;
	while (bullet_val-- > 0)
	{
		put_in->metaljacket[bullet_val] = put_in->metaljacket[bullet_val - 1]; // обратная (с конца) запись в стек Б
        // bullet_val--;
		// printing_array(put_in);
		// printf("___\n");
	}
	put_in->metaljacket[0] = put_out->metaljacket[0]; // обратная (с конца) запись в стек Б
	// printf("here\n");
	// // printing_array(put_in);
	// printing_array(put_out);
	bullet_val = 0;
	while (bullet_val != put_out->jacketlength - 1)
	{
		put_out->metaljacket[bullet_val] = put_out->metaljacket[bullet_val + 1]; // обратная (с конца) запись в стек Б
		bullet_val++;
	}
	put_in->jacketlength += 1;
	put_out->jacketlength -= 1;
}

//THIS FUNCTION ALSO WORKS
// void	pushing(t_toolbox *tools, t_metaljacket *dst, t_metaljacket *src)
// {
// 	int	i;
//
// 	src->jacketlength = tools->argv_num; // важно сохранить длину по кол-ву аргументов
// 	if (src->jacketlength > 0)
// 	{
// 		i = dst->jacketlength + 1; // увеличиваем итератор на длину назначения + 1 элемент который вкладываем
// 		while (--i > 0) // бежим с конца
// 			dst->metaljacket[i] = dst->metaljacket[i - 1]; // в ячейку кладем предыдущую
// 		dst->metaljacket[0] = src->metaljacket[0];// в нулевую назначения кладем нулевую источника
// 		i = -1;
// 		while (++i < src->jacketlength - 1) //уменьшаем длину источника на 1
// 			src->metaljacket[i] = src->metaljacket[i + 1]; // в ячейку кладем значение из след ячейки (поднимаем) по одной
// 		dst->jacketlength += 1;// увеличиваем длину назначения
// 		src->jacketlength -= 1;// уменьшаем длину
// 	}
// }

void pa(t_toolbox *tools)
{
	pushing( &tools->a, &tools->b);// перенос первого элемента из стека а в б
	ft_putstr_fd("pa\n", 1);
}

void pb(t_toolbox *tools)
{
	pushing(&tools->b, &tools->a);
	ft_putstr_fd("pb\n", 1);
}