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

#include "../push_swap.h"

void empty(t_dlist *r_lst, t_dlist *s_lst)
{
	r_lst->where = s_lst->where;
	s_lst->where->prev->next = s_lst->where->next;
	s_lst->where->next->prev = s_lst->where->prev;
	s_lst->where = s_lst->where->next;
	r_lst->length++;
	s_lst->length--;
	r_lst->where->prev = r_lst->where;
	r_lst->where->next = r_lst->where;
}

void one(t_dlist *dst, t_dlist *src)
{
	dst->where->prev->next = src->where;
	dst->where->prev = dst->where;
	src->where->prev = dst->where->prev;
	src->where->next = dst->where;
	dst->where = src->where;
	src->where = NULL;
	dst->length++;
	src->length--;
}

void mv(t_dlist *dst, t_dlist *src)
{
	t_dlink *nxt;
	t_dlink *prv;

	nxt = src->where->next;
	prv = src->where->prev;
	dst->where->prev->next = src->where;
	dst->where->prev = dst->where;
	src->where->prev = dst->where->prev;
	src->where->next = dst->where;
	dst->where = src->where;
	nxt->prev = prv;
	prv->next = nxt;
}

void ft_pa(t_pw *pw)
{
	if (pw->lst_b->length == 0)
		return;
	if (pw->lst_a->length == 0)
		empty(pw->lst_a, pw->lst_b);
	else
		one(pw->lst_a, pw->lst_b);
}

void ft_pb(t_pw *pw)
{
	if (pw->lst_a->length == 0)
		return;
	else if (pw->lst_b->length == 0)
		empty(pw->lst_b,pw->lst_a);
	else if (pw->lst_a->length == 1)
		one(pw->lst_b, pw->lst_a);
	else
		mv(pw->lst_b,pw->lst_a);
}