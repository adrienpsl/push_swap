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

void	push_by_median_push_2(int nb_top_pile, int med_push, t_stack stack)
{
	if (nb_top_pile >= med_push)
	{
		reset_quick_1(stack);
		do_inst('p', NO, stack);
	}
	else
	{
		reset_quick(stack);
		do_inst('p', NO, stack);
		do_inst('r', YES, stack);
	}
}

void	browse_push_2(t_stack stack, int nb_top_pile)
{
	t_med		med;
	t_browse	*browse;

	med = stack->med;
	browse = &stack->browse;
	if (browse->option == TRUE)
		push_by_median_push_2(nb_top_pile, med.medianne_push, stack);
	else
	{
		reset_quick(stack);
		do_inst('p', NO, stack);
	}
}

void	browser_reverse(t_stack stack, size_t med, size_t lim)
{
	size_t	top_pile;
	t_dll_c	pile;

	pile = stack->currrent_pile_dll;
	while (lim > 0)
	{
		do_inst('a', NO, stack);
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile < med) ||
			(stack->current_pile == 'B' && top_pile >= med))
			browse_push_2(stack, top_pile);
		else
		{
			if (stack->current_pile == 'A')
				reset_quick_1(stack);
		}
		--lim;
	}
	stack->browse.quick_count += 3;
}

void	browser_inverse(t_stack stack, size_t med, size_t lim)
{
	size_t	top_pile;
	t_dll_c	pile;

	pile = stack->currrent_pile_dll;
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile >= med) ||
			(stack->current_pile == 'B' && top_pile >= med))
		{
			browse_push_2(stack, top_pile);
		}
		else
			do_inst('r', NO, stack);
		--lim;
	}
	stack->browse.quick_count += 3;
}
