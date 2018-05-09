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

void set_middle_algo(t_dll_c pile, int quick)
{
	t_dll_l link;
	size_t lim;

	lim = pile->length;
	link = pile->top;
	while (lim > 0)
	{
		((t_data) link->content)->quick = quick;
		link = link->next;
		lim--;
	}
}

void first_passage_a(t_stack stack)
{
	t_dll_c pile;
	t_visualisateur visu;

	pile = stack->pile_a;
	visu = stack->visu;
	while (pile->length > 4)
	{
		set_stack('A', stack);
		browse_pile_a(stack, stack->currrent_pile_dll->length);
	}
	if (stack->pile_a->length == 3)
		sort_3_fuck_little(stack);
	else
		set_middle_algo(pile, stack->browse.quick_count + 1);

	print_stack(stack);
//	stack->visu->rec_pile = get_list_rec(visu->pile_b, visu->list_color);
//	print_list(visu, 50);
//	mlx_loop(visu->mlx_data.mlx);
	set_stack('A', stack);
}

void brain_verse(t_stack stack)
{
	get_med_quick(stack);
	browser_inverse(stack, stack->med.mediane, stack->quick.counter_quick);
}

void brain_reverse(t_stack stack)
{
	get_med_quick_rev(stack);
	browser_reverse(stack, stack->med.mediane, stack->quick.counter_quick);
}

void brain_is_beauty(t_stack stack)
{
	t_quick *quick;

	quick = &stack->quick;
	update_quick(stack);
	while (quick->counter_quick > 4 && stack->pile_b->length)
	{
		quick->sens == 'T' ?
		brain_verse(stack)
						   :
		brain_reverse(stack);
		update_quick(stack);
		print_stack(stack);
	}
	manage_all_short(stack);
}

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
		print_stack(stack);
	}
}

int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;
	int all_nb;

	struct_and_list_build(&argv, &stack, ac, av);

	destroy_argv(&argv);
	all_nb = stack->pile_a->length;
	if (all_nb <= 3)
		is_3_algo(stack);
	else
		is_more_3(stack);
	push_instruc_list(stack->last_instruct, stack);
	dll_print_str(stack->list_instruc);
	destroy_stack(&stack);
	return (EXIT_SUCCESS);
}
