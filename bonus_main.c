/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:49:31 by areggie           #+#    #+#             */
/*   Updated: 2022/03/02 12:59:15 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_or_not(t_toolbox *tools)
{
	int	i;

	i = 0;
	while (i != tools->argv_num - 1)
	{
		if (tools->a.metaljacket[i].bullet_value > \
		tools->a.metaljacket[i + 1].bullet_value)
			return (0);
		i++;
	}
	return (1);
}

void	init_stack_b_len(t_toolbox *tools)
{
	tools->b.metaljacket = malloc(sizeof(t_bullet) * tools->argv_num);
	if (!tools->array_for_sorting)
		error1();
	tools->b.jacketlength = 0;
}

int	validate_input_cmd(t_toolbox *tools, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		sa(tools);
	else if (!(ft_strcmp(line, "sb")))
		sb(tools);
	else if (!(ft_strcmp(line, "ss")))
		ss(tools);
	else if (!(ft_strcmp(line, "pa")))
		pa(tools);
	else if (!(ft_strcmp(line, "pb")))
		pb(tools);
	else if (!(ft_strcmp(line, "ra")))
		ra(tools);
	else if (!(ft_strcmp(line, "rb")))
		rb(tools);
	else if (!(ft_strcmp(line, "rr")))
		rr(tools);
	else if (!(ft_strcmp(line, "rra")))
		rra(tools);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(tools);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(tools);
	else
		return (0);
	return (1);
}

void	read_cmd_checksort(t_toolbox *tools)
{
	char	*line;
	int		read;

	while (1)
	{
		read = get_next_line(0, &line);
		if (!read)
			break ;
		if (!validate_input_cmd(tools, line))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		free(line);
	}
	if (check_sorted_or_not(tools) && tools->b.jacketlength == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_toolbox	*tools;

	tools = malloc(sizeof(t_toolbox));
	tools->argv_num = argv_counter(argv) - 1;
	validate_a_and_charge_metaljacket(argc, argv, tools);
	init_stack_b_len(tools);
	if (argc == 1)
		return (0);
	read_cmd_checksort(tools);
	exit(EXIT_SUCCESS);
}
