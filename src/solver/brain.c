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

void set_middle_algo(t_dll_c pile, int quick)
{
	t_dll_l link;
	size_t lim;

	lim = pile->length;
	link = pile->top;
	while (lim > 0)
	{
		((t_data) link->content)->quick = quick;
		link = link->next;
		lim--;
	}
}



void first_passage_a(t_stack stack)
{
	t_dll_c pile;
	pile = stack->pile_a;

	while (pile->length > 4)
	{
		set_stack('A', stack);
		browse_pile_a(stack, stack->currrent_pile_dll->length);
		if (ft_strchr(stack->argv, 'a'))
			print_stack(stack);
	}
	if (stack->pile_a->length == 3)
		sort_3_fuck_little(stack);
	else
		set_middle_algo(pile, stack->browse.quick_count + 1);
	if (ft_strchr(stack->argv, 'a') || ft_strchr(stack->argv, 'm'))
		print_stack(stack);

	print_stack(stack);
	test(stack);


	set_stack('A', stack);
}

void brain_verse(t_stack stack)
{
	get_med_quick(stack);
	browser_inverse(stack, stack->med.mediane, stack->quick.counter_quick);
}

void brain_reverse(t_stack stack)
{
	get_med_quick_rev(stack);
	browser_reverse(stack, stack->med.mediane, stack->quick.counter_quick);
}

void brain_is_beauty(t_stack stack)
{
	t_quick *quick;

	quick = &stack->quick;
	update_quick(stack);
	while (quick->counter_quick > 4 && stack->pile_b->length)
	{
		quick->sens == 'T' ?
		brain_verse(stack)
						   :
		brain_reverse(stack);
		update_quick(stack);
		if (ft_strchr(stack->argv, 'a') || ft_strchr(stack->argv, 'm'))
			print_stack(stack);
		test(stack);
	}
	manage_all_short(stack);
}
