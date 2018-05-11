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

void set_stack_visu(t_stack stack)
{
	stack->visu = new_visu(X_WINDOW, Y_WINDOW, "Push_Push");
	stack->visu->pile_a = stack->pile_a;
	stack->visu->pile_b = stack->pile_b;
	stack->v_data = new_dll();
	stack->color_tmp = new_dll();
}

void build_graf_link(t_stack stack)
{
	t_visualisateur visu;
	t_stack_visu_00 stack__v;
	t_dll_l link;

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

void build_graf_test_mem(t_stack stack)
{
	t_stack_visu_00 stack__v;
	t_dll_l link;

	stack__v.pile_a = get_list_rec(stack->pile_a, stack->color_tmp);
	stack__v.pile_b = get_list_rec(stack->pile_b, stack->color_tmp);
	link = new_dll_l(&stack__v, sizeof(t_stack_visu_00));
	dll_add(link, stack->v_data);
}

void create_graf_link(t_stack stack)
{
	(void) stack;

	build_graf_link(stack);
	//	build_graf_test_mem(stack);
}

void test_visu(t_stack stack)
{
	t_stack_visu stack_visu;
	stack_visu = stack->v_data->top->content;

	stack->visu->rec_pile = stack_visu->pile_a;
	print_list(stack->visu, 50);

	stack->visu->rec_pile = stack_visu->pile_b;
	print_list(stack->visu, 150);

	stack_visu = stack->v_data->top->next->content;

	stack->visu->rec_pile = stack_visu->pile_a;
	print_list(stack->visu, 250);

	stack->visu->rec_pile = stack_visu->pile_b;
	print_list(stack->visu, 350);
	mlx_loop(stack->visu->mlx_data.mlx);

	mlx_destroy_window(stack->visu->mlx_data.mlx, stack->visu->mlx_data.window);
}