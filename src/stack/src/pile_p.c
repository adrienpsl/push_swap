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

void pb(t_stack stack)
{
	t_dll_l link;
	t_dll_c pile_a;
	t_dll_c pile_b;

	pile_a = stack->pile_a;
	pile_b = stack->pile_b;
	if (pile_a->length < 1)
		return;
	link = dll_c_drop_link(pile_a);
	dll_c_push_link(link, pile_b);
}

void pa(t_stack stack)
{
	t_dll_l link;
	t_dll_c pile_a;
	t_dll_c pile_b;

	pile_a = stack->pile_a;
	pile_b = stack->pile_b;
	if (pile_b->length < 1)
		return;
	link = dll_c_drop_link(pile_b);
	dll_c_push_link(link, pile_a);
}
