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

#include "../../../header/stack_header.h"

void sa(t_stack stack)
{
	t_dll_c pile_a;
	int a;
	int b;

	pile_a = stack->pile_a;
	if (pile_a->length > 1)
	{
		a = get_int_ddl_l(pile_a->top);
		b = get_int_ddl_l(pile_a->top->next);
		*(int *)pile_a->top->content = b;
		*(int *)pile_a->top->next->content = a;
	}
}

void sb(t_stack stack)
{
	t_dll_c pile_b;
	int a;
	int b;

	pile_b = stack->pile_b;
	if (pile_b->length > 1)
	{
		a = get_int_ddl_l(pile_b->top);
		b = get_int_ddl_l(pile_b->top->next);
		*(int *)pile_b->top->content = b;
		*(int *)pile_b->top->next->content = a;
	}
}

void ss(t_stack stack)
{
	sa(stack);
	sb(stack);
}
