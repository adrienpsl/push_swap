/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/all_includes.h"

void dll_c_print_colorlst(t_dll_c lst, int a, int b)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;

	ft_printf("\033[0m");
	while (i != -1)
	{
		if (dll_l_get_int(link) >= a && dll_l_get_int(link) <= b)
			ft_printf("\033[0;31m");
		else
			ft_printf("\033[0m");
		ft_printf("%2d ", dll_l_get_int(link));
		i--;
		if (i == 0)
		{
			ft_printf(" -- ");
			ft_printf("%d \n", lst->length);
			break;
		}
		link = link->next;
	}
	ft_printf("\033[0m");
	ft_printf(" \n");
}

void print_stack2(t_stack stack, int a, int b)
{
	(void) stack;

	//	static t_sll_l last_prev_instruct = NULL;

	//print les instruction
	//	printf("\ninstrc : ");
	//	if (last_prev_instruct != NULL)
	//		sll_print_str_link(last_prev_instruct->next);
	//	else
	//		sll_print_str(stack->instruction);
	//	last_prev_instruct = stack->instruction->tail;

	printf("===================================== \n");
	//	printf("  med: %zu <> %zu, lim: %d <> %d ===== %d ---- %zu \n\n",
	//		   stack->mediane_down,
	//		   stack->mediane_up, stack->min_lim, stack->max_lim, stack->count,
	//		   stack->nb_already_sorted);

	// printe les lists
	//	printf("list_a : ");
	dll_c_print_colorlst(stack->pile_a, a, b);
	if (stack->pile_a->length == 0)
		printf(" \n");;

	//	printf("list_b : ");
	dll_c_print_colorlst(stack->pile_b, a, b);
	if (stack->pile_b->length == 0)
		printf(" \n");;


	//les mediane


	printf(" %d \n", stack->count);
};

size_t top_big_nb(t_dll_c pile, int nb)
{
	int nb_top;

	nb_top = dll_l_get_int(pile->top);
	return (nb_top > nb);
}


// je parcours la liste
// tout les nb qui sont les meilleurs je leurs met un,
// je prends le nb,  ;


int test_the_nb(t_dll_l tested_link, size_t lenght)
{
	size_t index;
	int nb_tested;
	int nb_current;
	int match;
	int difference;

	index = 0;
	match = 0;
	nb_tested = dll_l_get_int(tested_link);
	tested_link = tested_link->next;

	while (index < lenght )
	{

		nb_current = dll_l_get_int(tested_link);
		difference = nb_tested - nb_current;

		if (nb_current > nb_tested)
		{
			nb_tested = nb_current;
			match += 1;
		}

		else if (difference <= 2 && difference >= 0)
			match += 1;


		index += 1;
		tested_link = tested_link->next;
	}
	return (match);
}

int whose_the_best(t_dll_c list_a)
{
	size_t index;
	t_dll_l current_link;
	int current_nb;
	int score_current_nb;
	int new_score;

	index = 0;

	current_link = list_a->top;
	current_nb = dll_l_get_int(current_link);
	score_current_nb = test_the_nb(current_link, list_a->length - 1);

	while (index < list_a->length)
	{
		current_link = current_link->next;
		new_score = test_the_nb(current_link, list_a->length - 1);
		if (new_score > score_current_nb)
		{
			score_current_nb = new_score;
			current_nb = dll_l_get_int(current_link);
		}
		index++;
	}
	return (1);
}

int main(int ac, char **av)
{

	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	build_lst_a_index(stack->pile_a);
	whose_the_best(stack->pile_a);

	destroy_stack(&stack);
	destroy_argv(&argv);
	return (EXIT_SUCCESS);
}
