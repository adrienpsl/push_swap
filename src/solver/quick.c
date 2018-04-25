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

long count_quick(int quick_searched, t_dll_c pile, int sens)
{
	long nb_quick_in_pile;
	int current_quick;
	t_dll_l link;
	size_t size;

	nb_quick_in_pile = 0;
	size = 0;
	link = sens == TOP_PUSH ? pile->top : pile->top->prev;
	current_quick = get_quick(link);
	while (current_quick == quick_searched && size < pile->length)
	{
		link = sens == TOP_PUSH ? link->next : link->prev;
		current_quick = get_quick(link);
		nb_quick_in_pile += 1;
		size++;
	}
	return (nb_quick_in_pile);
}

int get_quick(t_dll_l link)
{
	return (((t_data) link->content)->quick);
}

void set_quick(t_stack stack)
{
	t_dll_l link;

	link = stack->current_pile == 'A' ? stack->pile_a->top : stack->pile_b->top;
	if (((t_data) link->content)->quick == 0)
		((t_data) link->content)->quick = stack->browse.quick_count;
}

void set_quick_1(t_stack stack)
{
	t_dll_l link;

	link = stack->current_pile == 'A' ? stack->pile_a->top : stack->pile_b->top;
	if (((t_data) link->content)->quick == 0)
		((t_data) link->content)->quick = stack->browse.quick_count + 1;
}