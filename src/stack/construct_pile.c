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

#include "../../header/stack_header.h"

void destroy_stack(t_stack *s)
{
	t_stack stack;

	stack = *s;
	if (stack->pile_a)
		destroy_dll_c(&stack->pile_a);
	if (stack->pile_b)
		destroy_dll_c(&stack->pile_b);
	free(stack);
	*s = NULL;
}


t_stack new_stack()
{
	t_stack stack;

	stack = (t_stack)ft_malloc_protect(sizeof(struct s_stack));
	stack->pile_a = NULL;
	stack->pile_b = new_dll_c();
	return (stack);
}