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
	t_v visu;
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

void print_lst(t_stack stack, t_stack_visu stack_visu, int option)
{
	stack->visu->rec_pile = stack_visu->pile_a;
	if (stack->visu->rec_pile->length > 0)
		print_list(stack->visu, 50, option);
	stack->visu->rec_pile = stack_visu->pile_b;
	if (stack->visu->rec_pile)
		print_list(stack->visu, 550, option);
}

void draw_pile(t_stack stack, t_stack_visu stack_visu)
{
	print_lst(stack, stack_visu, 0);
	mlx_put_image_to_window(stack->visu->mlx_data.mlx,
							stack->visu->mlx_data.window,
							stack->visu->mlx_data.img,
							0, 0);
	print_lst(stack, stack_visu, 1);
}

int tt(int key, void *p)
{
	t_stack stack;
	t_dll_l link;

	stack = p;
	link = stack->visu->visu_print_link;
	if (link == NULL)
		return (DONE);

	if (link != NULL)
	{
		draw_pile(stack, link->content);
	}

	stack->visu->visu_print_link = stack->visu->visu_print_link->next;

	printf("%d \n", key);
	return (FALSE);
}

void test_visu(t_stack stack)
{
	t_dll_l v_link;

	stack->visu->visu_print_link = stack->v_data->top;
	v_link = stack->v_data->top;
	draw_pile(stack, v_link->content);

	mlx_key_hook(stack->visu->mlx_data.window, tt, stack);
	mlx_loop(stack->visu->mlx_data.mlx);

	mlx_destroy_window(stack->visu->mlx_data.mlx, stack->visu->mlx_data.window);
}