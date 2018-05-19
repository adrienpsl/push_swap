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

void	set_stack(char name_pile, t_stack stack)
{
	stack->current_pile = name_pile == 'A' ? 'A' : 'B';
	stack->currrent_pile_dll =
		name_pile == 'A' ? stack->pile_a : stack->pile_b;
}

void	destroy_stack(t_stack *s)
{
	t_stack	stack;
	t_v		v;

	stack = *s;
	if (stack->pile_a)
		destroy_dll_c(&stack->pile_a);
	if (stack->pile_b)
		destroy_dll_c(&stack->pile_b);
	if (stack->list_instruc)
		destroy_dll(&stack->list_instruc);
	free(stack);
	*s = NULL;
}

t_stack	new_stack(void)
{
	t_stack stack;

	stack = ft_malloc_protect(sizeof(struct s_stack));
	ft_memset(stack, 0, sizeof(struct s_stack));
	stack->pile_a = NULL;
	stack->pile_b = new_dll_c();
	stack->list_instruc = new_dll();
	stack->browse.quick_count = 1;
	return (stack);
}
