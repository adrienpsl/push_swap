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

void		set_stack(char name_pile, t_stack stack)
{
	stack->current_pile = name_pile == 'A' ? 'A' : 'B';
	stack->currrent_pile_dll =
	 name_pile == 'A' ? stack->pile_a : stack->pile_b;
}
void		destroy_stack(t_stack *s)
{
	t_stack stack;

	stack = *s;
	if (stack->pile_a)
		destroy_dll_c(&stack->pile_a);
	if (stack->pile_b)
		destroy_dll_c(&stack->pile_b);
	if (stack->list_instruc)
		destroy_dll(&stack->list_instruc);
	free(stack);
	*s = NULL;
}

t_visualisateur new_visu(int x, int y, char *name)
{
	t_visualisateur visu;
	t_mlx_data mlx;

	visu = ft_malloc_protect(sizeof(t_visualisateur_00));
	visu->list_color = new_dll();
	mlx = &visu->mlx_data;

	mlx->mlx = mlx_init();
	mlx->x = x - 50;
	mlx->y = y - 50;
	mlx->window = mlx_new_window(mlx->mlx, x, y, name);

	return (visu);
}

t_stack		new_stack()
{
	t_stack stack;

	stack = (t_stack) ft_malloc_protect(sizeof(struct s_stack));
	ft_memset(stack, 0, sizeof(struct s_stack));
	stack->pile_a = NULL;
	stack->pile_b = new_dll_c();
	stack->list_instruc = new_dll();
	stack->browse.quick_count = 1;
	stack->visu = new_visu(X_WINDOW, Y_WINDOW, "Push_Push");
	stack->visu->pile_a = stack->pile_a;
	stack->visu->pile_b = stack->pile_b;
	stack->v_data = new_dll();
	return (stack);
}
