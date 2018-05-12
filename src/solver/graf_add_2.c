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

void	build_graf_link(t_stack stack)
{
	t_v				visu;
	t_stack_visu_00	stack__v;
	t_dll_l			link;

	visu = stack->visu;
	if (stack->pile_a->length)
		stack__v.pile_a = get_list_rec(stack->pile_a, visu->list_color);
	else
		stack__v.pile_a = NULL;
	if (stack->pile_b->length)
		stack__v.pile_b = get_list_rec(stack->pile_b, visu->list_color);
	else
		stack__v.pile_b = NULL;
	link = new_dll_l(&stack__v, sizeof(t_stack_visu_00));
	dll_add(link, stack->v_data);
}

void	build_graf_test_mem(t_stack stack)
{
	t_stack_visu_00	stack__v;
	t_dll_l			link;

	stack__v.pile_a = stack->pile_a->length ?
						get_list_rec(stack->pile_a, stack->color_tmp) :
						NULL;

	stack__v.pile_b = stack->pile_b->length ?
						get_list_rec(stack->pile_b, stack->color_tmp) :
						NULL;
	link = new_dll_l(&stack__v, sizeof(t_stack_visu_00));
	dll_add(link, stack->v_data);
}

void create_graf_link(t_stack stack)
{
	(void) stack;
	ft_strchr(stack->argv, 'v') ?
	build_graf_link(stack)
								:
	build_graf_test_mem(stack);
}