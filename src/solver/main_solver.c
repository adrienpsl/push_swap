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

void a_2_b_2(t_stack stack)
{
	int median;

	median = get_med(stack->pile_a, stack->pile_a->length);

	browse_pile_a(stack, median, stack->pile_a->length, FALSE);

	need_swap_a(stack);
	need_swap_b(stack);

	do_instruct("pa", stack);
	do_instruct("pa", stack);
}

void two_end_b(t_stack stack)
{
	do_instruct("rrb", stack);
	do_instruct("rrb", stack);
	need_swap_a(stack);
	need_swap_b(stack);
	do_instruct("pa", stack);
	do_instruct("pa", stack);
}

void b_2_2(t_stack stack)
{
	do_instruct("pa", stack);
	do_instruct("pa", stack);
	two_end_b(stack);

}

void nb_4_pile_b(t_stack stack)
{
	// je dois parcourir la moitier de la liste
	// je trouve la med et je fais une browser dessus
	// je reviens de deux en arriere et je vois si je dois swap
	// je met sur b

	int median;

	median = get_med(stack->pile_b, 4);

	browse_pile_b(stack, median, 4, FALSE);
	print_stack(stack);
	two_end_b(stack);
}

void nb_pile_b_last(t_stack stack)
{
	int median;

	median = get_med(stack->pile_b, 4);

	browse_pile_b(stack, median, 4, FALSE);
	print_stack(stack);
	need_swap_a(stack);
	need_swap_b(stack);
	do_instruct("pa", stack);
	do_instruct("pa", stack);
}

int main(int ac, char **av)
{

	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	build_lst_a_index(stack->pile_a);
	print_quick(stack->pile_a);


	// premier passsage
	int max = stack->pile_a->length / 2;
	if (stack->pile_a->length % 2)
		max++;

	browse_pile_a(stack, max, stack->pile_a->length, DEVANT_DERRIERE);

	print_stack(stack);
//	whose_the_best(stack->pile_a);

	max = max + max / 2;
	browse_pile_a(stack, max, stack->pile_a->length, DEVANT_DERRIERE);

	print_stack(stack);

	a_2_b_2(stack);
//	ft_printf("%d \n", count_quick(1, stack->pile_b));
	print_stack(stack);

	b_2_2(stack);
	print_stack(stack);

	nb_4_pile_b(stack);
	nb_pile_b_last(stack);
	print_stack(stack);

	
ft_printf("%d \n", stack->count);
	destroy_stack(&stack);
	destroy_argv(&argv);
	return (EXIT_SUCCESS);
}
