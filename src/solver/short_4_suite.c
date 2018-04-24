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

void is_abba(t_stack stack)
{
	do_instruct(m_inst('r', stack, FALSE), stack);
	do_instruct(m_inst('p', stack, FALSE), stack);
	do_instruct(m_inst('s', stack, FALSE), stack);
	do_ab(stack);
}

void is_bbaa(t_stack stack)
{
	do_instruct(m_inst('p', stack, FALSE), stack);
	do_instruct(m_inst('p', stack, FALSE), stack);
	need_swap(stack);
	do_instruct(m_inst('r', stack, FALSE), stack);
	do_instruct(m_inst('r', stack, FALSE), stack);
	do_instruct(m_inst('p', stack, NO_OP), stack);
	do_instruct(m_inst('p', stack, NO_OP), stack);
	do_instruct(stack->browse.pile == PILE_A ? "rra" : "rrb", stack);
	do_instruct(stack->browse.pile == PILE_A ? "rra" : "rrb", stack);
}

void is_aabb(t_stack stack)
{
	if (is_ordered(
	 stack->browse.pile == PILE_A ? stack->pile_a : stack->pile_b, 4))
		return;
	need_swap(stack);
	do_instruct(m_inst('r', stack, FALSE), stack);
	do_instruct(m_inst('r', stack, FALSE), stack);
	need_swap(stack);
	do_instruct(stack->browse.pile == PILE_A ? "rra" : "rrb", stack);
	do_instruct(stack->browse.pile == PILE_A ? "rra" : "rrb", stack);
}

void is_baba(t_stack stack)
{
	do_instruct(m_inst('p', stack, FALSE), stack);
	do_instruct(m_inst('r', stack, FALSE), stack);
	do_instruct(m_inst('s', stack, FALSE), stack);
	do_ab(stack);
}

void is_baab(t_stack stack)
{
	do_inst('p', NO, stack);
	do_instruct(m_inst('p', stack, FALSE), stack);
	print_stack(stack);
	do_instruct(m_inst('r', stack, FALSE), stack);
	print_stack(stack);
	do_ab(stack);
}