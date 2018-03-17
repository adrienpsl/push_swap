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

void print_top_a(t_stack stack)
{
	printf("%d ", get_int_ddl_l(stack->pile_a->top));
}

void get_first_pasage(t_stack stack)
{
	size_t i;
	size_t temp;
	//si i == taille max je switch

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
		do_instruct("pa",stack);
}

void beguin_pile_by_number(int nb, t_dll_c pile, char *instruct, t_stack stack)
{
	while (get_int_ddl_l(pile->top) != nb)
	{
	    do_instruct(instruct, stack);
	}
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

	get_first_pasage(stack);
	beguin_pile_by_number(stack->max_lim, stack->pile_b, "rb", stack);
	repush_b(stack);

	print_stack(stack);

	get_median(stack);

	get_first_pasage(stack);

	print_stack(stack);

	get_first_pasage(stack);
	beguin_pile_by_number(stack->max_lim, stack->pile_b, "rb", stack);
	beguin_pile_by_number(0, stack->pile_a, "ra", stack);
	print_stack(stack);
	repush_b(stack);
	beguin_pile_by_number(0, stack->pile_a, "ra", stack);
	print_stack(stack);
	printf("%d \n", stack->count);
	return (EXIT_SUCCESS);
}