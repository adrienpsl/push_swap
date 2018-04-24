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


//static void save_instruct_in_strack(char *instruct, t_stack stack)
//{
//	t_sll_l link;
//
//	link = new_sll_l(instruct, ft_strlen(instruct));
//	sll_add(link, stack->instruction);
//}

char *m_inst(char instruct, t_stack stack, int option)
{
	char *instr;
	instr = stack->instruct;
	instr[0] = instruct;
	if ((instruct == 'p' || option == FORCE_OP) && option != NO_OP)
		instr[1] = stack->browse.pile == PILE_A ? 'b' : 'a';
	else
		instr[1] = stack->browse.pile == PILE_A ? 'a' : 'b';
	instr[2] = 0;
	return (instr);
}

void do_instruct(char *instruc, t_stack stack)
{
	stack->count++;
	check_and_apply_instruct(instruc, stack);
	//	save_instruct_in_strack(instruc, stack);
	//	ft_printf("%s ",instruc);
}

char *
manage_instruction(char instruction, int op, t_stack stack, char tab_ins[])
{
	tab_ins[0] = instruction;
	if (instruction == 'p' && op == NO)
		tab_ins[1] = stack->current_pile == 'A' ? 'b' : 'a';
	else if (instruction == 'a')
	{
		tab_ins[0] = 'r';
		tab_ins[1] = 'r';
		tab_ins[2] = stack->current_pile == 'A' ? 'a' : 'b';
	}
	else
		tab_ins[1] = stack->current_pile == 'A'? 'a' : 'b';
	return (tab_ins);
}

void do_inst(char *raw_instruction, int option, t_stack stack)
{
	char instruction[4];

	ft_memset(instruction, 0, sizeof(char) * 4);
	manage_instruction(raw_instruction, option, stack, instruction);
	check_and_apply_instruct(instruction, stack);

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