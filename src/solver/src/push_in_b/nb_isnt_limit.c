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

#include "../../../../header/all_includes.h"

/*
**    = lst_a->top > lst_b->top
*/
static int who_is_bigger(t_stack stack)
{
	int nb_top_pile_a;
	int nb_top_pile_b;

	nb_top_pile_a = get_int_ddl_l(stack->pile_a->top);
	nb_top_pile_b= get_int_ddl_l(stack->pile_b->top);
	return (nb_top_pile_a > nb_top_pile_b);
}

static int top_a_is_bigger(t_dll_l top_link,t_dll_l link)
{
	int researched_nb;

	while (link_is_bigger_top(link, top_link) == TRUE)
		top_link = top_link->next;
	while (link_is_lower_top(link, top_link) == TRUE)
		top_link = top_link->next;
	researched_nb = get_int_ddl_l(top_link);
	return (researched_nb);
}

static int top_a_is_smaller(t_dll_l top_link,t_dll_l link)
{
	int researched_nb;

	while (link_is_lower_top(link, top_link) == TRUE)
		top_link = top_link->next;
	researched_nb = get_int_ddl_l(top_link);
	return (researched_nb);
}

void nb_isnt_limit(t_stack stack)
{
	t_dll_l link;
	t_dll_l top_link;
	int nb_researched;
	long nb_op;

	link = stack->pile_a->top;
	top_link = stack->pile_b->top;
	if (who_is_bigger(stack) == LIST_A)
		nb_researched = top_a_is_bigger(top_link, link);
	else
		nb_researched = top_a_is_smaller(top_link, link);
	nb_op = find_up_down(NULL, nb_researched, top_link,stack);
	do_the_ops_pileb(stack, nb_op);
	do_instruct("pb", stack);
}
