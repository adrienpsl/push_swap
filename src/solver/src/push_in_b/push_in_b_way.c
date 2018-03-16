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

int best_way(size_t by_top, t_stack stack)
{
	if (by_top > stack->pile_b->length / 2)
		return (APPLY_BY_BOTTOM);
	else
		return (APPLY_BY_TOP);
}

static long try_by_up(int researched_nb, t_dll_l top_link)
{
	long direction;

	direction = 0;
	while (top_is_research_nb(researched_nb, top_link) == FALSE)
	{
		direction += 1;
		top_link = top_link->next;
	}
	return (direction);
}

static int up_is_good_way(unsigned long direction, t_stack stack)
{
	return (direction < stack->pile_b->length / 2);
}

static long calcule_by_down(int researched_nb, t_dll_l top_link)
{
	long direction;

	direction = 0;
	while (top_is_research_nb(researched_nb, top_link) == FALSE)
	{
		direction += 1;
		top_link = top_link->prev;
	}
	return (direction * -1);
}

/*
**    trouve s'il est plus pertinent d'aller par le top ou le bas de la stack
**    pour depenser le moins possible de coup
*/
long
find_up_down(t_dll_l link, int researched_nb, t_dll_l top_link, t_stack stack)
{
	long direction;

	if (link != NULL)
		researched_nb = get_int_ddl_l(link);
	direction = try_by_up(researched_nb, top_link);
	if (up_is_good_way(direction, stack) == FALSE)
		direction = calcule_by_down(researched_nb, top_link);
	return (direction);
}

static void do_the_ops(t_stack stack, long operations)
{
	while (operations > 0)
	{
		do_instruct("rb", stack);
		operations--;
	}
	while (operations < 0)
	{
		do_instruct("rrb", stack);
		operations++;
	}
	do_instruct("pb", stack);
}

void nb_is_limit(t_stack stack)
{
	t_dll_l link_top;
	long nb_op;

	link_top = stack->pile_b->top;
	nb_op = find_up_down(NULL, stack->max_lim, link_top, stack);
	do_the_ops(stack, nb_op);
}

int is_normal(t_stack stack, int mode)
{
	size_t by_top;
	t_dll_l link_top;
	t_dll_l link;

	by_top = 0;
	link = stack->pile_a->top;
	link_top = stack->pile_b->top;

	while (1 &&
		   link_is_bigger_prev(link, link_top) == TRUE &&
		   link_is_lower_top(link, link_top) == TRUE)
	{
		by_top += 1;
		if (mode == SEARCH)
			link_top = link_top->next;
		else
		{
			if (mode == APPLY_BY_TOP)
				do_instruct("rb", stack);
			else if (mode == APPLY_BY_BOTTOM)
				do_instruct("rrb", stack);
			link_top = stack->pile_b->top;
		}
	}
	return (best_way(by_top, stack));
}

int is_biggest_lowest(t_stack stack, int mode)
{
	size_t by_top;
	t_dll_l link_top;

	by_top = 0;
	link_top = stack->pile_b->top;

	while (1 &&
		   current_is_the_biggest(link_top, stack) == FALSE)
	{
		by_top += 1;
		if (mode == SEARCH)
			link_top = link_top->next;
		else
		{
			if (mode == APPLY_BY_TOP)
				do_instruct("rb", stack);
			else if (mode == APPLY_BY_BOTTOM)
				do_instruct("rrb", stack);
			link_top = stack->pile_b->top;
		}
	}
	return (best_way(by_top, stack));
}
