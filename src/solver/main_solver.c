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

void first_passage_a(t_stack stack)
{
	t_dll_c pile;
	int median;

	pile = stack->pile_a;
	median = get_med(pile, pile->length);

	while (pile->length > 4)
	{
		set_brower(median, stack->pile_a->length, DEVANT_DERRIERE, stack);
		stack->browse.pile = PILE_A;
		stack->browse.stop = 4;
		browse_pile(stack, &stack->browse);
		//		browse_pile_a(stack, median, stack->pile_a->length, DEVANT_DERRIERE);
		//		print_stack(stack);
		median = get_med(pile, pile->length);
	}
	print_stack(stack);
	a_4(stack);
}

void reset_quick(t_dll_c pile)
{
	size_t size;
	t_dll_l link;

	size = pile->length;
	link = pile->top;
	while (size > 0)
	{
		set_quick(0, link);
		link = link->next;
		size--;
	}
}

void quick_quick(int *quick, int *counter_quick, t_stack stack)
{
	*quick = get_quick(stack->pile_b->top);
	*counter_quick = count_quick(*quick, stack->pile_b, TOP_PUSH);
}

void r(int a, t_stack stack)
{
	while (a > 0)
	{
		do_instruct("rrb", stack);
		a--;
	}
}

void quick_is_4(t_stack stack, int *quick, int *counter_quick)
{

	quick_quick(quick, counter_quick, stack);
	while (*counter_quick == 4)
	{
		if (*counter_quick == 4)
			b_4(stack);
		*counter_quick = count_quick(*quick, stack->pile_b, END_PUSH);

		if (*counter_quick == 4)
		{
			r(4,stack);
			b_4(stack);
		}
		quick_quick(quick, counter_quick, stack);
	}
	reset_quick(stack->pile_a);
}

void manage_b(t_stack stack)
{
	int quick;
	int counter_quick;
	int med;
	int retour;

	quick_quick(&quick, &counter_quick, stack);
	if (counter_quick == 4)
		quick_is_4(stack, &quick, &counter_quick);

//	print_stack(stack);

	med = get_med(stack->pile_b, counter_quick);


	set_brower(med, counter_quick, FALSE, stack);
	stack->browse.pile = PILE_B;

	//	if (counter_quick > 4)
	//	{
	//		set_brower()
	ft_printf("8888888 \n");
	print_stack(stack);
	retour = browse_pile(stack, &stack->browse);
	quick_quick(&quick, &counter_quick, stack);
	print_stack(stack);

	a_4(stack);
//	r(retour, stack);

	ft_printf(" --- %d %d %d\n", quick, counter_quick, med);
//	b_3(stack);
	print_stack(stack);
	//	}
}

int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	build_lst_a_index(stack->pile_a);
	print_quick(stack->pile_a);

	first_passage_a(stack);
	manage_b(stack);
	//	b_4(stack);



	//	print_stack(stack);
	ft_printf("%d \n", stack->count);
	destroy_stack(&stack);
	destroy_argv(&argv);
	return (EXIT_SUCCESS);
}
