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
	size_t four_remaining;

	pile = stack->pile_a;
	four_remaining = pile->length - 4;
	median = get_med(pile, pile->length);

	while (pile->length > 4)
	{
		set_brower(median, stack->pile_a->length, DEVANT_DERRIERE, stack);
		set_stack('A', stack);
		stack->browse.stop = 4;
		browse_pile_a(stack, &stack->browse, four_remaining);
		median = get_med(pile, pile->length);
	}
	sort_4(stack);
}

void manage_b(t_stack stack)
{
	t_quick quick;

	quick = stack->quick;
}

void is44(t_stack stack)
{
	stack->quick.sens == 'T' ?
	sort_4_top(stack) :
	sort_4_end(stack);
}

void is33(t_stack stack)
{
	stack->quick.sens == 'T' ?
	sort_3_top(stack) :
	sort_3_end(stack);
}

void is22(t_stack stack)
{
	stack->quick.sens == 'T' ?
	sort_2_top(stack) :
	sort_2_end(stack);
}

void test(t_stack stack)
{
	t_quick *quick;

	quick = &stack->quick;
	update_quick(stack);

	while (quick->counter_quick < 5)
	{
		if (quick->counter_quick == 4)
			is44(stack);
		else if (quick->counter_quick == 3)
			is33(stack);
		else if (quick->counter_quick == 2)
			is22(stack);
//		print_stack(stack);
		placed_quick_by_sort(stack);
		update_quick(stack);
	}
}

void test_2(t_stack stack)
{
	get_med_quick(stack);
	browser_inverse(stack, stack->browse.med, stack->quick.counter_quick, TRUE);
}

void test_2_rev(t_stack stack)
{
	get_med_quick_rev(stack);
	browser_reverse(stack, stack->browse.med, stack->quick.counter_quick, TRUE);
}


void ultra(t_stack stack)
{
	t_quick *quick;

	quick = &stack->quick;
	// get la ou il y a le plus grand

	update_quick(stack);
	while (quick->counter_quick > 4)
	{
		quick->sens == 'T' ?
		test_2(stack) :
		test_2_rev(stack);
		update_quick(stack);
		print_stack(stack);
	}
	test(stack);
}

int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	build_lst_a_index(stack->pile_a);

	first_passage_a(stack);


//	test(stack);
//	print_stack(stack);
//	test_2(stack);
//
//	test(stack);
//
//	get_med_quick_rev(stack);
//	browser_reverse(stack, stack->browse.med, stack->quick.counter_quick,
//					TRUE);
//	test(stack);
//	print_stack(stack);
//
//	ultra(stack);
//	print_stack(stack);
//
//	ft_printf("=====================================\n===================================== \n");


	while (stack->pile_b->length > 6)
	{
		ultra(stack);
		print_stack(stack);
	}






	//	print_quick(stack->pile_a);

	//	first_passage_a(stack);
	//	manage_b(stack);
	//
	//	stack->browse.pile = PILE_B;
	//	sort_3_front_b(stack);
	//
	//	do_instruct("ra", stack);
	//	do_instruct("ra", stack);
	//	do_instruct("ra", stack);
	//	do_instruct("ra", stack);
	//
	//	do_instruct("ra", stack);
	//	do_instruct("pb", stack);
	//	do_instruct("pb", stack);
	//	do_instruct("pb", stack);
	//	do_instruct("pb", stack);
	//		do_instruct("pb", stack);
	//	do_instruct("pb", stack);
	//	do_instruct("pb", stack);
	//	do_instruct("pb", stack);
	//
	//	set_stack('B', stack);
	//	set_stack('A', stack);
	//	print_stack(stack);
	//	sort_3_top(stack);
	//
	//	print_stack(stack);

	//	sort_4_top(stack);

	//	print_stack(stack);
	//	sort_4_end(stack);


	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);
	//	do_instruct("pa", stack);



	ft_printf("%d \n", stack->count);

	destroy_stack(&stack);
	destroy_argv(&argv);
	return (EXIT_SUCCESS);
}
