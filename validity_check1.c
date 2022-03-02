/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:03:11 by areggie           #+#    #+#             */
/*   Updated: 2022/03/02 12:37:19 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checking numbers and signs
int	input_validity_check(char **av, t_toolbox *tools, int argc)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (1);
	while (i < tools->argv_num + 1)
	{
		if (!input_numbers_signs_check(av, tools))
			return (0);
		i++;
	}
	return (1);
}

int	charging_a_metaljacket(char **argv, t_toolbox *tools )
{
	int	i;

	i = 0;
	while (i < tools->argv_num)
	{
		tools->a.metaljacket[i].bullet_value = ft_atoi(argv[i + 1]);
		i++;
	}
	tools->array_for_sorting = malloc(sizeof(int) * tools->argv_num);
	if (!tools->array_for_sorting)
		return (0);
	while (i-- > 0)
		tools->array_for_sorting[i] = tools->a.metaljacket[i].bullet_value;
	return (1);
}

int	checking_repeated_ints(t_toolbox *tools)
{
	int	left;
	int	right;

	left = 0;
	right = 1;
	while (left != tools->argv_num)
	{
		while (right != tools->argv_num)
		{
			if (tools->a.metaljacket[left].bullet_value == \
			tools->a.metaljacket[right].bullet_value)
				return (0);
			right++;
		}
		left++;
		right = left + 1;
	}
	return (1);
}

//проверка переполнения и если не инт или какой-то другой знак
int	check_overflow_notint(char **argv, t_toolbox *tools)
{
	int		i;
	char	*str;

	i = 0;
	while (i++ != tools->argv_num)
	{
		str = ft_itoa(ft_atoi(argv[i]));
		if (ft_strcmp(str, argv[i]) != 0)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

void	validate_a_and_charge_metaljacket(int argc, char **argv, \
t_toolbox *tools)
{
	if (!argc_number_checker(argc, tools))
		error1();
	if (input_validity_check(argv, tools, argc))
	{
		if (!check_overflow_notint(argv, tools))
			error1();
		init_stack_a_len(tools);
		if (!charging_a_metaljacket(argv, tools))
			error1();
		if (!checking_repeated_ints(tools))
			error1();
	}
	else
		error1();
}
