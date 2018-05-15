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


int check(char *s, void *ptr)
{
	(void) s;
	(void) ptr;
//	if (1
//		&& ft_strchr(s, ' ') != NULL
//		&& str_by_func(s, ft_isdigit) == TRUE)
//		return (' ');
	return (FALSE);
}


void	struct_and_list_build(t_argv *argv, t_stack *stack, int ac, char **av)
{
	*argv = new_argv("vam", ac, av);
	argv_set_check(check, check, *argv);
	*stack = get_stack_filled(*argv);
	build_lst_a_index((*stack)->pile_a);
}

void	is_3_algo(t_stack stack)
{
	set_stack('A', stack);
	if (stack->pile_a->length <= 2)
		need_swap(stack);
	if (stack->pile_a->length == 3)
		sort_3_fuck_little(stack);
}

void	is_more_3(t_stack stack)
{
	first_passage_a(stack);
	if (stack->pile_a->length == 4 && stack->pile_b->length == 0)
		sort_4_top(stack);
	while (stack->pile_b->length)
	{
		brain_is_beauty(stack);
		if (ft_strchr(stack->argv, 'a') || ft_strchr(stack->argv, 'm'))
			print_stack(stack);
		create_graf_link(stack);
	}
}

void	dll_print_str2(t_dll lst)
{
	t_dll_l link;

	link = lst->top;
	while (link)
	{
		ft_printf("%s", link->content);
		link = link->next;
	}
}


int		main(int ac, char **av)
{
	t_argv	argv;
	t_stack	stack;
	int		all_nb;

	struct_and_list_build(&argv, &stack, ac, av);
	set_stack_visu(stack);
	stack->argv = argv->option_found;
	all_nb = stack->pile_a->length;
	if (all_nb)
	{
		if (all_nb <= 3)
			is_3_algo(stack);
		else
			is_more_3(stack);
		push_instruc_list(stack->last_instruct, stack);
		dll_print_str2(stack->list_instruc);
		if (stack->pile_a->length > 20 && ft_strchr(stack->argv, 'v'))
			test_visu(stack);
	}
	destroy_argv(&argv);
	destroy_stack(&stack);
	return (EXIT_SUCCESS);
}
