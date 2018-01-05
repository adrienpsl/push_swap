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

#include "../../../push_swap.h"

static size_t loop_speed_way(t_solver *s, t_dlist *lst, int sens)
{

	lst->head = lst->where;
	if (sens == HEAD)
	{
		if (s->nb > gn(lst->head))
			return (loop_taller_head(s, lst));
		else
			return (loop_smaller_head(s, lst));
	}
	else
	{
		if (s->nb > gn(lst->head))
			return (loop_taller_tail(s, lst));
		else
			return (loop_smaller_tail(s, lst));
	}
}

static int the_speed_way(t_solver *s, t_dlist *lst)
{
	int head;
	int tail;

	if (lst->where == NULL)
		return (s->op = UP);
	if (lst->length == 1)
		return (s->op = ONE);
//	head = loop_speed_way(s, lst, HEAD);
	tail = loop_speed_way(s, lst, TAIL);
	head = 1000;
//	tail = 1000;
	s->index = head < tail ? head : tail;
	return (s->op = head < tail ? UP : DOWN);
}

void check_lim(t_solver *s, t_pw *pw)
{
	if (s->nb < pw->lim.med)
		the_speed_way(s, pw->lst_b);
	else
	{
		s->op = KEEP_LEFT;
		s->i++;
		pw->lst_a->where = pw->lst_a->where->next;
	}
}