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

#include "../../includes/all_includes.h"

int		is_ordered(t_dll_c c_list, size_t lenght)
{
	size_t	i;
	t_dll_l	link;
	t_dll_l	next;

	i = 1;
	link = c_list->top;
	next = link->next;
	while (i < lenght)
	{
		if (dll_l_get_int(link) >= dll_l_get_int(next))
		{
			ft_printf("KO\n");
			return (FALSE);
		}
		link = next;
		next = link->next;
		++i;
	}
	ft_printf("OK\n");
	return (TRUE);
}

int		is_ordered_link(t_dll_l link, size_t lenght)
{
	size_t	i;
	t_dll_l	next;

	i = 1;
	next = link->next;
	while (i < lenght)
	{
		if (dll_l_get_int(link) >= dll_l_get_int(next))
			return (FALSE);
		link = next;
		next = link->next;
		++i;
	}
	return (TRUE);
}

void	do_intructions(t_argv argv, t_stack stack)
{
	char *instruct;

	while (argv_get_next_argv(&instruct, argv) == TRUE)
	{
		check_and_apply_instruct(instruct, stack);
	}
}

int		main(int ac, char **av)
{
	t_argv	argv;
	t_stack	stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);
	do_intructions(argv, stack);
	if (stack->pile_a->length)
		is_ordered(stack->pile_a, stack->pile_a->length);
	destroy_argv(&argv);
	destroy_stack(&stack);
	return (EXIT_SUCCESS);
}
