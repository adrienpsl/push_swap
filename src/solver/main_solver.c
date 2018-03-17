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

size_t need_pb(t_stack stack)
{
	size_t nb_top;

	nb_top = get_int_ddl_l(stack->pile_a->top);
	return (nb_top < stack->mediane_up && nb_top >= stack->mediane_down);
}

void get_first_pasage(t_stack stack)
{
	size_t i;
	size_t temp;

	temp = stack->pile_a->length;
	i = 0;
	while (i < temp)
	{
		if (need_pb(stack))
			push_in_b(stack);
		else
			do_instruct("ra", stack);
		printf(" \n\n");
		print_stack(stack);
		i++;
	}
}

void repush_b(t_stack stack)
{
	while (stack->pile_b->length != 0)
	{
		do_instruct("pa", stack);
	}
}

void
set_good_beguin(int researched_nb, t_dll_l top_link, int pile, t_stack stack)
{
	int opt;

	opt = find_up_down(NULL, researched_nb, top_link, stack);
	if (pile == LIST_A)
		do_the_ops_pilea(stack, opt);
	else if (pile == LIST_B)
		do_the_ops_pileb(stack, opt);
}

int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	build_lst_a_index(stack->pile_a);
	get_median(stack);

	dll_c_print_lst(stack->pile_a);
	printf(" =================\n");

	// premier pasage
	get_first_pasage(stack);
	repush_b(stack);
	print_stack(stack);

	// deuxieme passage
	get_median(stack);
	get_first_pasage(stack);
	print_stack(stack);

	set_good_beguin(stack->max_lim, stack->pile_b->top, LIST_B, stack);
	print_stack(stack);
	set_good_beguin(0, stack->pile_a->top, LIST_A, stack);

	print_stack(stack);
	repush_b(stack);
	set_good_beguin(0, stack->pile_a->top, LIST_A, stack);
	printf(" \n");
	print_stack(stack);
	printf("%d \n", stack->count);
	return (EXIT_SUCCESS);
}