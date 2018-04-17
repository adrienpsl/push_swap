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

// annalyser si je fais un swap a et ou b
void need_swap_a(t_stack stack)
{
	int a;
	int b;
	t_dll_c pile;

	pile = stack->pile_a;
	a = dll_l_get_int(pile->top);
	b = dll_l_get_int(pile->top->next);
	if (a > b)
	{
		do_instruct("sa", stack);
	}
}

void need_swap_b(t_stack stack)
{
	int a;
	int b;
	t_dll_c pile;

	pile = stack->pile_b;
	a = dll_l_get_int(pile->top);
	b = dll_l_get_int(pile->top->next);
	if (a < b)
	{
		do_instruct("sb", stack);
	}
}

void manage_end_algo(t_stack stack)
{
	int median;

	median = get_med(stack->pile_a, stack->pile_a->length);

	browse_pile_a(stack, median, stack->pile_a->length, FALSE);

	need_swap_a(stack);
	need_swap_b(stack);

	do_instruct("pa", stack);
	do_instruct("pa", stack);
}
// je fait le premier passage
//je trouve une solution pour manager les medianne

// fonction qui parcours une liste de a a b en et push des nb qui sont inferieurs a ce que je veux


void devant_derriere(int nb, int max, t_stack stack)
{
	if (nb >= max)
		do_instruct("pb", stack);
	else
	{
		do_instruct("pb", stack);
		do_instruct("rb", stack);
	}
}

int med_devant_derriere(t_stack stack, int max, size_t lim)
{
	int nb_link;
	t_dll_l link;
	t_dll_l link_copie;
	t_dll_c pile_copie;
	int median;

	pile_copie = new_dll_c();
	link = stack->pile_a->top;
	while (lim > 0)
	{
		nb_link = dll_l_get_int(link);
		if (nb_link <= max)
		{
			link_copie = new_dll_l(link->content, sizeof(int));
			dll_c_push_link(link_copie, pile_copie);
		}
		lim -= 1;
		link = link->next;
	}

	// dll_c_print_lst(pile_copie);

	median = get_med(pile_copie, pile_copie->length);
	destroy_dll_c(&pile_copie);
	return (median);
}

#define DEVANT_DERRIERE 1
// stop le passage quand la lsite du bas est pleine
void browse_pile_a(t_stack stack, int max, size_t lim, int option)
{
	int top_pile;
	t_dll_c pile;
	int med_devant_derrier;

	pile = stack->pile_a;
	if (option == DEVANT_DERRIERE)
		med_devant_derrier = med_devant_derriere(stack, max, lim);
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if (top_pile < max)
		{
			if (option == DEVANT_DERRIERE)
				devant_derriere(top_pile, med_devant_derrier, stack);
			else
				do_instruct("pb", stack);
		}
		else
			do_instruct("ra", stack);
		lim -= 1;
//		print_stack(stack);
	}
}

int main(int ac, char **av)
{

	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	build_lst_a_index(stack->pile_a);

	// premier passsage
	int max = stack->pile_a->length / 2;
	if (stack->pile_a->length % 2)
		max++;

	browse_pile_a(stack, max, stack->pile_a->length, DEVANT_DERRIERE);

	print_stack(stack);
	whose_the_best(stack->pile_a);

	max = max + max / 2;
	browse_pile_a(stack, max, stack->pile_a->length, DEVANT_DERRIERE);
	print_stack(stack);

	manage_end_algo(stack);

	print_stack(stack);

	destroy_stack(&stack);
	destroy_argv(&argv);
	return (EXIT_SUCCESS);
}
