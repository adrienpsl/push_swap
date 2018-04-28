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
	return (direction <= stack->pile_b->length / 2);
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

long
find_up_down(t_dll_l link, int researched_nb, t_dll_l top_link, t_stack stack)
{
	long direction;

	if (link != NULL)
		researched_nb = dll_l_get_int(link);
	direction = try_by_up(researched_nb, top_link);
	if (up_is_good_way(direction, stack) == FALSE)
		direction = calcule_by_down(researched_nb, top_link);
	return (direction);
}