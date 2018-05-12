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

void set_stack(char name_pile, t_stack stack)
{
	stack->current_pile = name_pile == 'A' ? 'A' : 'B';
	stack->currrent_pile_dll =
	 name_pile == 'A' ? stack->pile_a : stack->pile_b;
}

void destoye_link(t_dll_l link)
{
	(void) link;
	t_stack_visu stack_v;

	stack_v = link->content;
	if (stack_v->pile_a)
		destroy_dll(&stack_v->pile_a);
	if (stack_v->pile_b)
		destroy_dll(&stack_v->pile_b);
	free(link->content);
}

void destroy_stack(t_stack *s)
{
	t_stack stack;

	stack = *s;
	if (stack->pile_a)
		destroy_dll_c(&stack->pile_a);
	if (stack->pile_b)
		destroy_dll_c(&stack->pile_b);
	if (stack->list_instruc)
		destroy_dll(&stack->list_instruc);
	if (stack->color_tmp)
		destroy_dll(&stack->color_tmp);
	if (stack->v_data)
		destroy_dll_func(&stack->v_data, &destoye_link);
	free(stack);
	*s = NULL;
}

t_visualisateur new_visu(int x, int y, char *name)
{
	t_visualisateur visu;
	t_mlx_data mlx;
	int a;
	int b;
	int c;

	visu = ft_malloc_protect(sizeof(t_visualisateur_00));
	visu->list_color = new_dll();
	mlx = &visu->mlx_data;
	mlx->mlx = mlx_init();
	mlx->x = x - 50;
	mlx->y = y - 50;
	mlx->window = mlx_new_window(mlx->mlx, x, y, name);
	mlx->img = mlx_new_image(mlx->mlx, X_WINDOW, Y_WINDOW);
	mlx->str_img = mlx_get_data_addr(mlx->img, &a, &b, &c);

	return (visu);
}

t_stack new_stack()
{
	t_stack stack;

	stack = (t_stack) ft_malloc_protect(sizeof(struct s_stack));
	ft_memset(stack, 0, sizeof(struct s_stack));
	stack->pile_a = NULL;
	stack->pile_b = new_dll_c();
	stack->list_instruc = new_dll();
	stack->browse.quick_count = 1;
	return (stack);
}
