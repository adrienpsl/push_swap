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

static void
struct_and_list_build(t_argv *argv, t_stack *stack, int ac, char **av)
{
	*argv = new_argv(ac, av);
	*stack = get_stack_filled(*argv);
	build_lst_a_index((*stack)->pile_a);
}

static void is_3_algo(t_stack stack)
{
	set_stack('A', stack);
	if (stack->pile_a->length <= 2)
		need_swap(stack);
	if (stack->pile_a->length == 3)
		sort_3_fuck_little(stack);
}

static void is_more_3(t_stack stack)
{
	first_passage_a(stack);
	while (stack->pile_b->length)
	{
		brain_is_beauty(stack);
		if (ft_strchr(stack->argv, 'a') || ft_strchr(stack->argv, 'm'))
			print_stack(stack);
	}
}

void set_stack_visu(t_stack stack)
{
	stack->visu = new_visu(X_WINDOW, Y_WINDOW, "Push_Push");
	stack->visu->pile_a = stack->pile_a;
	stack->visu->pile_b = stack->pile_b;
	stack->v_data = new_dll();
}

void yo(t_stack stack)
{
	t_visualisateur visu;
	t_stack_visu_00 stack__v;
	t_dll_l link;

	visu = stack->visu;
	stack__v.pile_a = get_list_rec(stack->pile_a, visu->list_color);
	stack__v.pile_b = get_list_rec(stack->pile_b, visu->list_color);
	link = new_dll_l(&stack__v, sizeof(t_stack_visu_00));
	dll_add(link, stack->v_data);
}

void yo2(t_stack stack)
{
	t_stack_visu_00 stack__v;
	t_dll_l link;

	stack__v.pile_a = get_list_rec(stack->pile_a, stack->color_tmp);
	stack__v.pile_b = get_list_rec(stack->pile_b, stack->color_tmp);
	link = new_dll_l(&stack__v, sizeof(t_stack_visu_00));
	dll_add(link, stack->v_data);
}

void test(t_stack stack)
{
	(void) stack;

	//	yo(stack);
	yo2(stack);
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

void destoye_link(t_dll_l link)
{
	(void)link;
		t_stack_visu stack_v;

	stack_v = link->content;
	destroy_dll(&stack_v->pile_a);
	destroy_dll(&stack_v->pile_b);
	free(link->content);
}

int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;
	int all_nb;

	struct_and_list_build(&argv, &stack, ac, av);

	////////////////////////////////////////////////
	//	set_stack_visu(stack);

	stack->v_data = new_dll();
	stack->color_tmp = new_dll();

	stack->argv = argv->taken_options;
	all_nb = stack->pile_a->length;
	if (all_nb <= 3)
		is_3_algo(stack);
	else
		is_more_3(stack);
	push_instruc_list(stack->last_instruct, stack);
	dll_print_str(stack->list_instruc);

	/////////////////////////////////////////////
	//	test_visu(stack);


	destroy_dll_func(&stack->v_data, &destoye_link);
	destroy_dll(&stack->color_tmp);

	destroy_argv(&argv);
	destroy_stack(&stack);
	return (EXIT_SUCCESS);
}
