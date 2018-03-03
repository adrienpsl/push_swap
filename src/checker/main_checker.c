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

#include "../../header/header_checker.h"

//void is_ordered(t_dll pile_a)
//{
//	size_t i;
//	t_dll_l link;
//	t_dll_l next;
//
//	i = 1;
//	link = pile_a->where;
//	next = pile_a->where->next;
//	pile_a->cc.print_circular_nb(pile_a, ' ');
//	while (i < pile_a->length)
//	{
//		if (link->mm.get_content_int(link) >= next->mm.get_content_int(next))
//			no_argv("KO", 0);
//		link = next;
//		next = link->next;
//		++i;
//	}
//	no_argv("OK", 0);
//}



void do_intructions(t_stack stack, t_argv argv)
{
	char *instruct;

	(void)stack;
	while (argv_get_next_argv(&instruct, argv) == TRUE)
	{
	    printf("%s \n",instruct);
	}
}

t_stack get_stack_filled(t_argv argv)
{
	t_stack stack;

	stack = new_stack();
	stack->pile_a = get_list_a(argv, ACTIVATE);
	return (stack);
}

int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	do_intructions(stack,argv);
	
	return (EXIT_SUCCESS);
}