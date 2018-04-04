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

void is_ordered(t_dll_c c_list)
{
	size_t i;
	t_dll_l link;
	t_dll_l next;

	i = 1;
	link = c_list->top;
	next = link->next;
	while (i < c_list->length)
	{
		if (get_int_ddl_l(link) >= get_int_ddl_l(next))
		{
			ft_putstr_fd("KO",2);
			exit(42);
		}
		link = next;
		next = link->next;
		++i;
	}
	ft_putstr("ok \n");
}

void do_intructions(t_argv argv, t_stack stack)
{
	char *instruct;

	while (argv_get_next_argv(&instruct, argv) == TRUE)
	{
		check_and_apply_instruct(instruct, stack);
	}
}


//
//int main(int ac, char **av)
//{
//	t_argv argv;
//	t_stack stack;
//
//	argv = new_argv(ac, av);
//	stack = get_stack_filled(argv);
//	do_intructions(argv, stack);
//	is_ordered(stack->pile_a);
//
//	return (EXIT_SUCCESS);
//}