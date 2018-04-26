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

void get_med_quick(t_stack stack)
{
	stack->browse.med = get_med(stack->currrent_pile_dll,
								stack->quick.counter_quick);
}

void get_med_quick_rev(t_stack stack)
{
	t_dll_c pile;
	int i;

	pile = new_dll_c();
	pile->top = stack->currrent_pile_dll->top;
	pile->length = stack->quick.counter_quick;;

	i = stack->quick.counter_quick;
	while (i)
	{
		pile->top = pile->top->prev;
		--i;
	}
	stack->browse.med = get_med(pile,
								stack->quick.counter_quick);
}

void devant_derriere(int nb, int max, t_stack stack)
{
	if (nb >= max)
	{
		set_quick_1(stack);
		do_inst('p', NO, stack);
	}
	else
	{
		set_quick(stack);
		do_inst('p', NO, stack);
		do_inst('r', YES, stack);
	}
}

void get_median_push(t_dll_c pile, t_browse *browse)
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
		if (nb_link <= browse->med)
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

static void browse_push(t_browse *browse, t_stack stack, int top_pile, int med)
{

	if (browse->option == DEVANT_DERRIERE)
		devant_derriere(top_pile, med, stack);
	else
	{
		set_quick(stack);
		do_inst('p', NO, stack);
	}
}

int browse_pile(t_stack stack, t_browse *browse)
{
	size_t top_pile;
	t_dll_c pile;
	size_t lim;
	int retour;

	retour = 0;
	lim = browse->lim;
	pile = stack->currrent_pile_dll;
	get_median_push(pile, browse);
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if ((browse->pile == PILE_A && top_pile < browse->med) ||
			(browse->pile == PILE_B && top_pile >= browse->med))
			browse_push(browse, stack, top_pile, browse->median_push);
		else
		{
			do_inst('r', NO, stack);
			retour++;
		}
		lim -= 1;
		if (pile->length == browse->stop)
			break;
		//		print_stack(stack);
		//		ft_printf("%d \n", stack->count);
	}
	browse->quick_count += 2;
	return (retour);
}

void
browse_pile_a(t_stack stack, t_browse *browse, size_t four_remaining)
{
	size_t top_pile;
	t_dll_c pile;
	size_t lim;

	lim = browse->lim;
	pile = stack->currrent_pile_dll;
	get_median_push(pile, browse);
	if ((lim / 2) / 2 % 2 && lim > 6)
		browse->median_push--;
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if (top_pile < browse->med &&
			top_pile < four_remaining)
			browse_push(browse, stack, top_pile, browse->median_push);
		else
			do_inst('r', NO, stack);
		lim -= 1;
		if (pile->length == browse->stop)
			break;
		//		ft_printf("%d \n", stack->count);
	}
	browse->quick_count += 2;
}

void set_brower(int med, size_t lim, int option, t_stack stack)
{
	t_browse *browse;

	browse = &stack->browse;
	ft_memset(browse, 0, (sizeof(*browse) - sizeof(size_t)));
	browse->lim = lim;
	browse->count = lim;
	browse->med = med;
	browse->option = option;
}