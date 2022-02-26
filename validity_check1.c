/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:03:11 by areggie           #+#    #+#             */
/*   Updated: 2022/02/26 17:48:27 by areggie          ###   ########.fr       */
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
		tools->a.metaljacket[i].bullet_value = ft_atoi(argv[i + 1]);//сохраняем значения в патроны-элементы //(массива патронов - metaljacket типа патрон)
		i++;
		// printf("inside = %d ", i);
	}
	tools->array_for_sorting = malloc(sizeof(int) * tools->argv_num);//cоздание массива- магазина структур-патронов под количество патронов
	if (!tools->array_for_sorting)
		return (0);
	// printf("outside = %d \n", i);
	while (i-- > 0) //запись с конца итератором в массив который будет отсортирован
	{
		tools->array_for_sorting[i] = tools->a.metaljacket[i].bullet_value; // в массиве запоминаем поданные числа как подали
		// i;
		// printf("in = %d ", i);
	}

	//printing out tools->array_for_sorting
	// int j = 0;
	// while (j != tools->argv_num)
	// {
	// 	printf("=%d ", tools->array_for_sorting[j]);
	// 	j++;
		
	// } 
	
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
	while (i++ != tools->argv_num) //прошли по нулю и увеличили итератор на след цикле
	{
		str = ft_itoa(ft_atoi(argv[i])); //интересная проверка
		if (ft_strcmp(str, argv[i]) != 0) //если разные значения
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

void init_stack_a_len(t_toolbox *tools)
{
	tools->a.metaljacket = malloc(sizeof(t_bullet) * tools->argv_num); //cоздание массива- магазина структур-патронов под количество патронов
	if (!tools->a.metaljacket)
		error1();
	tools->a.jacketlength = tools->argv_num;//число патронов в магазине а
}

void	validate_a_and_charge_metaljacket(int argc, char **argv, t_toolbox *tools)
{
	if (!argc_number_checker(argc, tools))
		error1();
	if (input_validity_check(argv, tools, argc))	//проверка валидности (числа- не числа, знак, переполнение)
	{
		if (!check_overflow_notint(argv, tools))
			error1();
		init_stack_a_len(tools);
		if (!charging_a_metaljacket(argv, tools))
				error1();
		if (!checking_repeated_ints(tools)) //проверка повторов
			error1();
	}
	else
		error1();
}

