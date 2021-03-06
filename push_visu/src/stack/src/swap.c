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

#include "../../../includes/all_includes.h"

static int		test_swap_a(t_stack stack)
{
	int			a;
	int			b;
	t_dll_c		pile;

	pile = stack->pile_a;
	a = dll_l_get_int(pile->top);
	b = dll_l_get_int(pile->top->next);
	if (a - b == +1)
	{
		return (TRUE);
	}
	return (FALSE);
}

static int		test_swap_b(t_stack stack)
{
	int			a;
	int			b;
	t_dll_c		pile;

	pile = stack->pile_b;
	a = dll_l_get_int(pile->top);
	b = dll_l_get_int(pile->top->next);
	if (a - b == -1)
	{
		return (TRUE);
	}
	return (FALSE);
}

void			need_swap_a(t_stack stack)
{
	int			a;
	int			b;
	t_dll_c		pile;

	pile = stack->pile_a;
	a = dll_l_get_int(pile->top);
	b = dll_l_get_int(pile->top->next);
	if (a - b == +1)
	{
		do_instruct("sa\n", stack);
	}
}

void			need_swap_b(t_stack stack)
{
	int			a;
	int			b;
	t_dll_c		pile;

	pile = stack->pile_b;
	a = dll_l_get_int(pile->top);
	b = dll_l_get_int(pile->top->next);
	if (a - b == -1)
	{
		do_instruct("sb\n", stack);
	}
}

void			need_swap(t_stack stack)
{
	if (stack->pile_b->length)
	{
		if (test_swap_a(stack) && test_swap_b(stack))
			do_instruct("ss\n", stack);
		else
		{
			if (stack->pile_a->length)
			{
				need_swap_a(stack);
			}
			if (stack->pile_b->length)
				need_swap_b(stack);
		}
	}
	else
		need_swap_a(stack);
}
