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

void	ra(t_stack stack)
{
	t_dll_c pile_a;

	pile_a = stack->pile_a;
	if (pile_a->length > 1)
	{
		pile_a->top = pile_a->top->next;
	}
}

void	rb(t_stack stack)
{
	t_dll_c pile_b;

	pile_b = stack->pile_b;
	if (pile_b->length > 1)
	{
		pile_b->top = pile_b->top->next;
	}
}

void	rr(t_stack stack)
{
	ra(stack);
	rb(stack);
}