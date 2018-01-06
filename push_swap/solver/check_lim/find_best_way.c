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

static int next_nb(t_pw *pw)
{
	pw->lst_a->where = pw->lst_a->where->next;
	pw->loop.sens = KEEP_LEFT;
	return (1);
}

static void first_call(t_pw *pw)
{
	ft_pb(pw);
	pw->loop.lst->tail = pw->loop.lst->where;
	pw->loop.lst->head = pw->loop.lst->where;
}

static void one_el(t_pw *pw)
{
	ft_pb(pw);
	if (pw->loop.nb > *(int *) pw->lst_b->where->next->content)
		ft_rb(pw);
}

static void put_by_head(t_pw *pw)
{
	if (pw->loop.end)
		return (one_el(pw));
	while (pw->loop.nb_operation > 0)
	{
		ft_rb(pw);
		pl(pw->lst_b);
		pw->loop.nb_operation -= 1;
	}
		ft_pb(pw);
}

void set_min_max(t_pw *pw)
{
	if (pw->loop.nb > gn(pw->loop.lst->head))
		pw->loop.lst->head = pw->loop.lst->where;
	if (pw->loop.nb < gn(pw->loop.lst->tail))
		pw->loop.lst->tail = pw->loop.lst->where;
}

static int the_speed_way(t_loop *loop)
{
	size_t head;
	//	int tail;

	head = nb_taller_head(loop);
	loop->nb_operation = head;
	//	tail = loop_speed_way(s, lst, TAIL);
	//	head = 1000;
	//	tail = 1000;
	//	s->index = head < tail ? head : tail;
	//	return (s->op = head < tail ? UP : DOWN);
	return (1);
}

int find_best_way(t_pw *pw)
{
	t_dlist *lst;

	lst = pw->loop.lst;
	if (pw->loop.nb < pw->mediane)
	{
		if (lst->length == 0)
			first_call(pw);
		else if (lst->length == 1)
			one_el(pw);
		else
		{
			the_speed_way(&pw->loop);
			put_by_head(pw);
		}
		set_min_max(pw);
	}
	else
		return (next_nb(pw));
	return (0);
}