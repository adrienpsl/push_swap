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

void get_median_push2(t_dll_c pile, t_browse *browse)
{
	size_t nb_link;
	t_dll_l link;
	t_dll_l link_copie;
	t_dll_c pile_copie;
	size_t lim;

	pile_copie = new_dll_c();
	link = pile->top;
	lim = browse->lim;
	while (lim > 0)
	{
		nb_link = dll_l_get_int(link);
		if (nb_link >= browse->med)
		{
			link_copie = new_dll_l(link->content, sizeof(int));
			dll_c_push_link(link_copie, pile_copie);
		}
		lim -= 1;
		link = link->next;
	}
	if (pile_copie->length < 5)
		browse->option = 0;
	browse->median_push = get_med(pile_copie, pile_copie->length);
	destroy_dll_c(&pile_copie);
}

void devant_derriere2(int nb, int max, t_stack stack)
{
	if (nb >= max)
	{
		reset_quick(stack);
		do_inst('p', NO, stack);
	}
	else
	{
		set_quick(stack);
		do_inst('p', NO, stack);
		do_inst('r', YES, stack);
	}
}

static void browser_push(t_stack stack, int need_quick)
{
	//	if (stack->quick.counter_quick > 4)
	//		devant_derriere2(
	//		 dll_l_get_int(stack->currrent_pile_dll->top),
	//		 stack->browse.median_push,
	//		 stack);
	need_quick == TRUE && reset_quick(stack);
	do_inst('p', NO, stack);
}

void browser_push2(t_stack stack, int need_quick)
{
	if (stack->quick.counter_quick > 9)
		devant_derriere2(
		 dll_l_get_int(stack->currrent_pile_dll->top),
		 stack->browse.median_push,
		 stack);
	else
	{
		need_quick == TRUE && reset_quick(stack);
		do_inst('p', NO, stack);
	}
}

void browser_inverse(t_stack stack, size_t med, size_t lim, int need_quick)
{
	size_t top_pile;
	t_dll_c pile;
	int a = 6;

//	if (stack->quick.quick == 4)
//		a = 6;
	pile = stack->currrent_pile_dll;
	if (stack->quick.quick == 2)
		a = 5;
	get_median_push2(stack->currrent_pile_dll, &stack->browse);
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile >= med) ||
			(stack->current_pile == 'B' && top_pile >= med))
		{
			if (a == 1)
				browser_push(stack, need_quick);
			else
				browser_push2(stack, need_quick);
		}
		else
			do_inst('r', NO, stack);
		--lim;
		if (a == 5)
			print_stack(stack);
	}
	need_quick == TRUE && stack->browse.quick_count++;
}

void browser(t_stack stack, size_t med, size_t lim, int need_quick)
{
	size_t top_pile;
	t_dll_c pile;

	get_median_push2(stack->currrent_pile_dll, &stack->browse);
	pile = stack->currrent_pile_dll;
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile < med) ||
			(stack->current_pile == 'B' && top_pile >= med))
			browser_push(stack, need_quick);
		else
			do_inst('r', NO, stack);
		--lim;
	}
	need_quick == TRUE && stack->browse.quick_count++;
}

void browser_reverse(t_stack stack, size_t med, size_t lim, int need_quick)
{
	size_t top_pile;
	t_dll_c pile;

	pile = stack->currrent_pile_dll;
	while (lim > 0)
	{
		do_inst('a', NO, stack);
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile < med) ||
			(stack->current_pile == 'B' && top_pile >= med))
			browser_push(stack, need_quick);
		--lim;
	}
	need_quick == TRUE && stack->browse.quick_count++;
}