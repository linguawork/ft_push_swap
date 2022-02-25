/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:16:29 by areggie           #+#    #+#             */
/*   Updated: 2022/02/25 22:26:16 by areggie          ###   ########.fr       */
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


void insertion_sort_array(t_toolbox *tools)
{
	int i; 
	int tmp;

	i = 0;   
    while(i < tools->argv_num ) // нолевой уже находится на месте
    {
        int k = i; // копирование ячейки с которой стартуем
        while (k > 0 && tools->array_for_sorting[k-1] > tools->array_for_sorting[k] )// Ascending order двигаем позицию влево пока там не ноль т.е. пока позиция слева
        // имеет значение больше ноля: K > 0 т.е. пока тот элемент слева, который имеет позиицию(k-1) сущ
        {
            //swap меняем местами - меньшее двигаем влево
            tmp = tools->array_for_sorting[k-1];// сохраняем значение левого
            tools->array_for_sorting[k-1] = tools->array_for_sorting[k];// значение левого перезаписываем правым
            tools->array_for_sorting[k] = tmp;// значение правого перезаписываем сохраненным значением левого
            //при этом сами названия переменных не меняем
            k -= 1; //переходим на след элемент левее
            //https://www.youtube.com/watch?v=ROalU379l3U
            //сортировка в танце
        } 
		i++;
    }
}

//return index of the sorted array that matches a number in the given array 
int match_index_to_number(int *sorted_array, int metaljacket_bullet)
{
	int	i; 

	i = 0; 
	while(sorted_array[i] != metaljacket_bullet)
			i++;
	return(i);
}

void record_indexes_into_metaljacket(t_toolbox *tools)
{
	int	i; 
	
	i = 0;
	
	while (i != tools->argv_num)
	{
		tools->a.metaljacket[i].bullet_index = \
		match_index_to_number(tools->array_for_sorting, 
		tools->a.metaljacket[i].bullet_value);
		i++;
	}
}

void sorting(t_toolbox *tools)
{	
	sort2(tools);
	sort3(tools);//2 -3 operations ok
	sort4(tools); // not more than 12 ops
	
	insertion_sort_array(tools);// to get the indexes of the sorted array we sort the sorting array
	
	//printing out tools->array_for_sorting
	// int j = 0;
	// while (j != tools->argv_num)
	// {
	// 	printf("=%d ", tools->array_for_sorting[j]);
	// 	j++;		
	// } 
	
	record_indexes_into_metaljacket(tools); //record indexes field in the stucture of bullet
	if(tools->a.jacketlength == 5)
		sort5_(tools);
	else if (tools->a.jacketlength > 5)
		sortmore(tools);
	// printing_array(&tools->a);// final print
}



int	main(int argc, char **argv)
{
	t_toolbox	*tools; //ptr to struct
	tools = malloc(sizeof(t_toolbox)); //malloc for the struct
	tools->argv_num = argv_counter(argv) - 1; // число argv не считая argc (наименование бинарника)
	validate_a_and_charge_metaljacket(argc, argv, tools);

	// int i = 0;
	// while (i != tools->argv_num)
	// {
	// 	printf("%d ", tools->array_for_sorting[i]);
	// } //распечатка отсортированного
	if(!check_sorted_or_not(tools)) // если 0 те неотсорт
	{
		
		// write(1, "ok\n", 4);
		init_stack_b_len(tools);// маллок б
	 	sorting(tools); 
		
	}
	// DEBUG operation functions
	// debug_rotating(tools);
	// debug_pushing(tools);
	// debug_swapping(tools);
	// debug_rev_rotating(tools);

	// sleep(20); //check leaks with valid cases
	// stdout->_ptr = stdout->_base;
	// ft_memset(stdout, 0, sizeof(stdout));
	// fputs("\033c", stderr);
	// fflush(stderr);
	exit(EXIT_SUCCESS);
}
