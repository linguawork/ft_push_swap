/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:35:23 by areggie           #+#    #+#             */
/*   Updated: 2022/03/02 12:39:12 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error1(void)
{	
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	argc_number_checker(int argc, t_toolbox *tools)
{
	if (argc - 1 != tools->argv_num)
		return (0);
	return (1);
}

//можно не считать аргументы так как программа сама считает argc 
//(можно от нее отнять 1)
int	argv_counter(char **av)
{
	int	arg_count;

	arg_count = 0;
	while (av[arg_count])
		++arg_count;
	return (arg_count);
}

int	ft_isdigit_plus(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	if (av[0] == '-')
		i++;
	if (av[0] == '+')
		i++;
	while (av[i])
	{
		if (!(av[i] >= 48 && av[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

// проверка подаваемых значений на знаки и числа // 0 - не числа
int	input_numbers_signs_check(char **av, t_toolbox *tools)
{
	int	i;

	i = 0;
	while (++i < tools->argv_num + 1)
	{
		if (!ft_isdigit_plus(av[i]))
			return (0);
	}
	return (1);
}
