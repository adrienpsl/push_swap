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

void clear_wind(t_stack stack)
{
	t_fig_2_00 fg;

	ft_memset(&fg, 0, sizeof(t_fig_2_00));
	fg.x_2 = X_WINDOW;
	fg.y_2 = Y_WINDOW;
	recangle(&fg, &stack->visu->mlx_data);
}

void draw_pile(t_stack stack, t_stack_visu stack_visu)
{
	stack->visu->rec_pile = stack_visu->pile_a;
	print_list(stack->visu, 50);
	stack->visu->rec_pile = stack_visu->pile_b;
	print_list(stack->visu, 550);
}

int tt(int key, void *p)
{
	t_stack stack;
	t_dll_l link;

	stack = p;
	link = stack->visu->visu_print_link;
	if (link == NULL)
		return (DONE);
	clear_wind(p);

	if (link != NULL)
	{
				draw_pile(stack, link->content);
		/////////////////////////////////////////////////
//		fill_pixel(stack->visu->mlx_data.str_img, 0, 0, 0xff0000);
		/////////////////////////////////////////////////

		mlx_put_image_to_window(stack->visu->mlx_data.mlx,
								stack->visu->mlx_data.window,
								stack->visu->mlx_data.img,
								0, 0);
	}

	stack->visu->visu_print_link = stack->visu->visu_print_link->next;

	printf("%d \n", key);
	return (FALSE);
}

void set_img()
{
}

void test_visu(t_stack stack)
{
	t_dll_l v_link;

	stack->visu->visu_print_link = stack->v_data->top;
	v_link = stack->v_data->top;
		draw_pile(stack, v_link->content);
		clear_wind(stack);

	///////////////////////////////////////////////////////
//	fill_pixel(stack->visu->mlx_data.str_img, 0, 0, 0xff0000);
//	fill_pixel(stack->visu->mlx_data.str_img, 1, 0, 0xff0000);
//	fill_pixel(stack->visu->mlx_data.str_img, 2, 0, 0xff0000);
//
//	fill_pixel(stack->visu->mlx_data.str_img, 3, 1, 0xff00ff);
//	fill_pixel(stack->visu->mlx_data.str_img, 3, 2, 0xff00ff);
//	fill_pixel(stack->visu->mlx_data.str_img, 3, 3, 0xff00ff);
//	mlx_put_image_to_window(stack->visu->mlx_data.mlx,
//							stack->visu->mlx_data.window,
//							stack->visu->mlx_data.img,
//							0, 0);
	///////////////////////////////////////////////////


	mlx_key_hook(stack->visu->mlx_data.window, tt, stack);
	mlx_loop(stack->visu->mlx_data.mlx);

	//	mlx_destroy_window(stack->visu->mlx_data.mlx, stack->visu->mlx_data.window);
}