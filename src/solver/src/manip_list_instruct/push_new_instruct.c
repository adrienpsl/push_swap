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

#include "../../../../header/all_includes.h"


static void save_instruct_in_strack(char *instruct, t_stack stack)
{
	t_sll_l link;

	link = new_sll_l(instruct, ft_strlen(instruct));
	sll_add(link, stack->instruction);
}

void do_instruct(char *instruc, t_stack stack)
{
	stack->count++;
	check_and_apply_instruct(instruc, stack);
	save_instruct_in_strack(instruc, stack);
}

void do_the_ops_pileb(t_stack stack, long nb_operations)
{
	while (nb_operations > 0)
	{
		do_instruct("rb", stack);
		nb_operations--;
	}
	while (nb_operations < 0)
	{
		do_instruct("rrb", stack);
		nb_operations++;
	}
}

void do_the_ops_pilea(t_stack stack, long nb_operations)
{
	while (nb_operations > 0)
	{
		do_instruct("ra", stack);
		nb_operations--;
	}
	while (nb_operations < 0)
	{
		do_instruct("rra", stack);
		nb_operations++;
	}
}