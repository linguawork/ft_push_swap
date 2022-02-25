/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:22:21 by areggie           #+#    #+#             */
/*   Updated: 2022/02/25 21:28:54 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_value_to_top4(t_toolbox *tools)
{
	int	 i;
	
	i = 0;
	while (i != tools->a.jacketlength)
	{
		if(tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[1].bullet_value
			&& tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[2].bullet_value
			&& tools->a.metaljacket[0].bullet_value < tools->a.metaljacket[3].bullet_value)
			return (0);
		ra(tools);	
	}
	return (1);
}


void	sort4(t_toolbox *tools)
{
	if (tools->a.jacketlength == 4)
	{
		min_value_to_top4(tools);
		// printing_array(&tools->a);
		pb(tools);
		// printing_array(&tools->a);
		// printing_array(&tools->b);
		sort3(tools);
		// printing_array(&tools->a);
		pa(tools);
		// printing_array(&tools->a);
	}
}

int	define_min_index(t_metaljacket mj)
{
	int	i; 
	int min_mark;

	i = 0;
	min_mark = mj.metaljacket[i].bullet_index;
	while( i < mj.jacketlength)
	{
		if(mj.metaljacket[i].bullet_index < min_mark)
			min_mark = mj.metaljacket[i].bullet_index;
		i++;
	}
	return(min_mark);
	
}

int compare_before_after_median(t_metaljacket mj, int median)
{
	int	len_after; 
	int	len_before;
	int	full_len;

	full_len = mj.jacketlength - 1;
	len_before = full_len;
	while(mj.metaljacket[len_before].bullet_index != median)
			len_before--;
	len_before = full_len - len_before;
	len_after = 0; 
	while(mj.metaljacket[len_after].bullet_index != median)
			len_after++;
	if(len_before < len_after)
			return (1);
	return (0);
}
	
void	sort5_(t_toolbox *tools)
{
	int	i;
	int min;
		
	i = 0;
	while( i < tools->argv_num - 2)
	{
        min = define_min_index(tools->a);
		if (tools->a.metaljacket[0].bullet_index > min
		&& !compare_before_after_median(tools->a, min))
			ra(tools);
		else if (tools->a.metaljacket[0].bullet_index > min
		&& compare_before_after_median(tools->a, min))
			rra(tools);
		else
		{
			pb(tools);
			i++;
		}
        // printing_array(&tools->a);
		// printing_array(&tools->b);
	}
	if (tools->a.metaljacket[0].bullet_index != min)
    {
        sort2(tools);
        // printing_array(&tools->a);
        // printing_array(&tools->b);
    }
	while(tools->b.jacketlength)
    {
        pa(tools);
        // printing_array(&tools->a);
        // printing_array(&tools->b);
    }
}