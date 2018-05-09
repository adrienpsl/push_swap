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

#include "../../../header/all_includes.h"

void			check_and_apply_instruct(char *str, t_stack stack)
{
	if (ft_strcmp("sa", str) == FALSE)
		sa(stack);
	else if (ft_strcmp("sb", str) == FALSE)
		sb(stack);
	else if (ft_strcmp("ss", str) == FALSE)
		ss(stack);
	else if (ft_strcmp("pa", str) == FALSE)
		pa(stack);
	else if (ft_strcmp("pb", str) == FALSE)
		pb(stack);
	else if (ft_strcmp("ra", str) == FALSE)
		ra(stack);
	else if (ft_strcmp("rb", str) == FALSE)
		rb(stack);
	else if (ft_strcmp("rr", str) == FALSE)
		rr(stack);
	else if (ft_strcmp("rra", str) == FALSE)
		rra(stack);
	else if (ft_strcmp("rrb", str) == FALSE)
		rrb(stack);
	else if (ft_strcmp("rrr", str) == FALSE)
		rrr(stack);
	else
		exit_wrong_nb();
}

static void		pile_a(char instruction, int op, char tab_ins[])
{
	tab_ins[0] = instruction;

	if (instruction == 'p')
		tab_ins[1] = op == NO ? 'b' : 'a';
	else if (instruction == 'a')
	{
		tab_ins[0] = 'r';
		tab_ins[1] = 'r';
		tab_ins[2] = op == NO ? 'a' : 'b';
	}
	else
		tab_ins[1] = op == NO ? 'a' : 'b';
}

static void		pile_b(char instruction, int op, char tab_ins[])
{
	tab_ins[0] = instruction;

	if (instruction == 'p')
		tab_ins[1] = op == NO ? 'a' : 'b';
	else if (instruction == 'a')
	{
		tab_ins[0] = 'r';
		tab_ins[1] = 'r';
		tab_ins[2] = op == NO ? 'b' : 'a';
	}
	else
		tab_ins[1] = op == NO ? 'b' : 'a';
}

void			do_inst(char raw_instruction, int option, t_stack stack)
{
	char instruction[4];

	ft_memset(instruction, 0, sizeof(char) * 4);
	stack->current_pile == 'A' ?
	pile_a(raw_instruction, option, instruction) :
	pile_b(raw_instruction, option, instruction);
	do_instruct(instruction, stack);
}

void			push_instruc_list(char *intruct, t_stack stack)
{
	t_dll_l link;

	link = new_dll_l(intruct, ft_strlen(intruct));
	dll_add(link, stack->list_instruc);
}
