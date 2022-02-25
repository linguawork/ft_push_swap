/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:17:21 by areggie           #+#    #+#             */
/*   Updated: 2022/02/25 18:54:52 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "limits.h"
# include "libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_bullet{
	int				bullet_index;
	int				bullet_value;
}					t_bullet; // у патрона есть индекс и цифров значение

typedef struct s_metaljacket{
	int				jacketlength;
	t_bullet		*metaljacket;// магазин (массив) патронов  (с ячейками-патронами)
}					t_metaljacket;

typedef struct s_toolbox{
	int				argv_num;//число аргументов без бинарника - argc
	t_metaljacket	a;//тип магазина
	t_metaljacket	b;
	int				*array_for_sorting;
}					t_toolbox;

int		input_validity_check(char **av, t_toolbox *tools, int argc);
int		charging_a_metaljacket(char **argv, t_toolbox *tools);
int		checking_repeated_ints(t_toolbox *tools);
int		check_overflow_notint(char **argv, t_toolbox *tools);
int		argv_counter(char **av);
int		input_numbers_signs_check(char **av, t_toolbox *tools);
int		argc_number_checker(int argc, t_toolbox *tools);
void	error1(void);
void	validate_a_and_charge_metaljacket(int argc, char **argv, \
		t_toolbox *tools);
void	rotating(t_toolbox *tools, t_metaljacket *metjacket);
void	swapping(t_toolbox *tools, t_metaljacket *metaljacket);
void	pushing( t_metaljacket *put_in, t_metaljacket *put_out);
void	rev_rotate(t_metaljacket *metjacket);
void	sa(t_toolbox *tools);
void	pb(t_toolbox *tools);
void	pa(t_toolbox *tools);
void 	rra(t_toolbox *tools);
void 	ra(t_toolbox *tools);
void 	rb(t_toolbox *tools);
void 	rrb(t_toolbox *tools);
void	sort2(t_toolbox *tools);
void 	sort3(t_toolbox *tools);
int		min_value_to_top4(t_toolbox *tools);
int		min_value_to_top5(t_toolbox *tools);
void	sort4(t_toolbox *tools);
void	sort5_(t_toolbox *tools);
int		compare_before_after_median(t_metaljacket mj, int median);
void	sortmore(t_toolbox *tools);

//FOR DEBUG
void	debug_rotating(t_toolbox *tools);
void	debug_pushing(t_toolbox *tools);
void	debug_swapping(t_toolbox *tools);
void	debug_rev_rotating(t_toolbox *tools);
void	printing_array( t_metaljacket *arr);


#endif