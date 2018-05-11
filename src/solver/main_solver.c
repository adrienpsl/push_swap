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

static void
struct_and_list_build(t_argv *argv, t_stack *stack, int ac, char **av)
{
	*argv = new_argv(ac, av);
	*stack = get_stack_filled(*argv);
	build_lst_a_index((*stack)->pile_a);
}

static void is_3_algo(t_stack stack)
{
	set_stack('A', stack);
	if (stack->pile_a->length <= 2)
		need_swap(stack);
	if (stack->pile_a->length == 3)
		sort_3_fuck_little(stack);
}

static void is_more_3(t_stack stack)
{
	first_passage_a(stack);
	while (stack->pile_b->length)
	{
		brain_is_beauty(stack);
		if (ft_strchr(stack->argv, 'a') || ft_strchr(stack->argv, 'm'))
			print_stack(stack);
		create_graf_link(stack);
	}
}


int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;
	int all_nb;

	struct_and_list_build(&argv, &stack, ac, av);
	set_stack_visu(stack);

	stack->argv = argv->taken_options;
	all_nb = stack->pile_a->length;
	if (all_nb <= 3)
		is_3_algo(stack);
	else
		is_more_3(stack);
	push_instruc_list(stack->last_instruct, stack);
	dll_print_str(stack->list_instruc);


	/////////////////////////////////////////////
	test_visu(stack);

	destroy_argv(&argv);
	destroy_stack(&stack);
	return (EXIT_SUCCESS);
}
