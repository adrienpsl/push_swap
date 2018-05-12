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

void	set_stack_visu(t_stack stack)
{
	stack->visu = new_visu(X_WINDOW, Y_WINDOW, "Push_Push");
	stack->visu->pile_a = stack->pile_a;
	stack->visu->pile_b = stack->pile_b;
	stack->v_data = new_dll();
	stack->color_tmp = new_dll();
}

void	print_lst(t_stack stack, t_stack_visu stack_visu, int option)
{
	stack->visu->rec_pile = stack_visu->pile_a;
	if (stack->visu->rec_pile->length > 0)
		print_list(stack->visu, 50, option);
	stack->visu->rec_pile = stack_visu->pile_b;
	if (stack->visu->rec_pile)
		print_list(stack->visu, 550, option);
}

void	draw_pile(t_stack stack, t_stack_visu stack_visu)
{
	print_lst(stack, stack_visu, 0);
	mlx_put_image_to_window(stack->visu->mlx_data.mlx,
							stack->visu->mlx_data.window,
							stack->visu->mlx_data.img,
							0, 0);
	print_lst(stack, stack_visu, 1);
}

int		hook_key(int key, void *p)
{
	t_stack stack;
	t_dll_l link;

	stack = p;
	(void)key;
	link = stack->visu->visu_print_link;
	if (link == NULL)
		return (DONE);
	if (link != NULL)
	{
		draw_pile(stack, link->content);
	}
	stack->visu->visu_print_link = stack->visu->visu_print_link->next;
	return (FALSE);
}

void	test_visu(t_stack stack)
{
	t_dll_l v_link;

	stack->visu->visu_print_link = stack->v_data->top;
	v_link = stack->v_data->top;
	draw_pile(stack, v_link->content);
	mlx_key_hook(stack->visu->mlx_data.window, hook_key, stack);
	mlx_loop(stack->visu->mlx_data.mlx);
	mlx_destroy_window(stack->visu->mlx_data.mlx, stack->visu->mlx_data.window);
}
