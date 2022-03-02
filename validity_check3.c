/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:51:02 by areggie           #+#    #+#             */
/*   Updated: 2022/03/02 12:51:30 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a_len(t_toolbox *tools)
{
	tools->a.metaljacket = malloc(sizeof(t_bullet) * tools->argv_num);
	if (!tools->a.metaljacket)
		error1();
	tools->a.jacketlength = tools->argv_num;
}
