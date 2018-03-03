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

void rra(t_stack stack)
{
	t_dll_c pile_a;

	pile_a = stack->pile_a;
	if (pile_a->length > 1)
	{
		pile_a->top = pile_a->top->prev;
	}
}

void rrb(t_stack stack)
{
	t_dll_c pile_b;

	pile_b = stack->pile_b;
	if (pile_b->length > 1)
	{
		pile_b->top = pile_b->top->prev;
	}
}

void rrr(t_stack stack)
{
	rra(stack);
	rrb(stack);
}