/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:49:28 by areggie           #+#    #+#             */
/*   Updated: 2022/02/27 20:48:23 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing(t_metaljacket *put_in, t_metaljacket *put_out)
{
	int	bullet_val;

	bullet_val = put_in->jacketlength + 1;
	while (bullet_val-- > 0)
		put_in->metaljacket[bullet_val] = put_in->metaljacket[bullet_val - 1];
	put_in->metaljacket[0] = put_out->metaljacket[0];
	bullet_val = 0;
	while (bullet_val != put_out->jacketlength - 1)
	{
		put_out->metaljacket[bullet_val] = put_out->metaljacket[bullet_val + 1];
		bullet_val++;
	}
	put_in->jacketlength += 1;
	put_out->jacketlength -= 1;
}

void	pa(t_toolbox *tools)
{
	pushing(&tools->a, &tools->b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_toolbox *tools)
{
	pushing(&tools->b, &tools->a);
	ft_putstr_fd("pb\n", 1);
}
