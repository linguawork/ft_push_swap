/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:49:31 by areggie           #+#    #+#             */
/*   Updated: 2022/02/26 23:31:35 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted_or_not(t_toolbox *tools)
{
	int	i;
	
	i = 0;
	while(i != tools->argv_num - 1) // - 1 чтобы в конце смотреть на последний элемент массива и на за массив
	{
		if (!(tools->array_for_sorting[i] < tools->array_for_sorting[i + 1]))
				return (0);
		i++;
	}
	return (1);
}

void init_stack_b_len(t_toolbox *tools)
{
	tools->b.metaljacket = malloc(sizeof(t_bullet) * tools->argv_num); //cоздание массива- магазина структур-патронов под количество патронов
	if (!tools->array_for_sorting)
		error1();
	tools->b.jacketlength = 0; //иниц длину под ноль
}

int	check_command(t_toolbox *vars, char *line)
{
	if (!(ft_strcmp(line, "sa\n")))
		sa(vars);
	else if (!(ft_strcmp(line, "sb\n")))
		sb(vars);
	else if (!(ft_strcmp(line, "ss\n")))
		ss(vars);
	else if (!(ft_strcmp(line, "pa\n")))
		pa(vars);
	else if (!(ft_strcmp(line, "pb\n")))
		pb(vars);
	else if (!(ft_strcmp(line, "ra\n")))
		ra(vars);
	else if (!(ft_strcmp(line, "rb\n")))
		rb(vars);
	else if (!(ft_strcmp(line, "rr\n")))
		rr(vars);
	else if (!(ft_strcmp(line, "rra\n")))
		rra(vars);
	else if (!(ft_strcmp(line, "rrb\n")))
		rrb(vars);
	else if (!(ft_strcmp(line, "rrr\n")))
		rrr(vars);
	else
		return (0);
	return (1);
}

void	run_reader(t_toolbox *vars)
{
	char	*line;
	int		read;

	while (1)
	{
		read = get_next_line(0, &line);
		if (!read)
			break ;
		if (!check_command(vars, line))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		free(line);
	}
	if (check_sorted_or_not(vars) && vars->b.jacketlength == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_toolbox	*tools; //ptr to struct
	tools = malloc(sizeof(t_toolbox)); //malloc for the struct
	tools->argv_num = argv_counter(argv) - 1; // число argv не считая argc (наименование бинарника)
	validate_a_and_charge_metaljacket(argc, argv, tools);
	init_stack_b_len(tools);// маллок б
	run_reader(tools);

	exit(EXIT_SUCCESS);
}