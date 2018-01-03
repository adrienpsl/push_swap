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
void o(t_dlink *o)
{
	printf("%d \n", *(int *) o->content);
	printf("nxt  %d \n", *(int *) o->next->content);
	printf("prev %d \n", *(int *) o->prev->content);
}
void one(t_dlist *dst, t_dlist *src)
{

	t_dlink *new;
	t_dlink *prev;
	t_dlink *nxt;

	new = src->where;
	prev = dst->where->prev;
	nxt = dst->where;
	new->next = nxt;
	nxt->prev = new;
	new->prev = prev;
	prev->next = new;
	dst->where = src->where;
	src->where = NULL;
	dst->length++;
	src->length--;
}

void empty(t_dlist *dst, t_dlist *src)
{
	dst->where = src->where;
	src->where->prev->next = src->where->next;
	src->where->next->prev = src->where->prev;
	src->where = src->where->next;
	dst->length++;
	src->length--;
	dst->where->prev = dst->where;
	dst->where->next = dst->where;
}

void mv(t_dlist *dst, t_dlist *src)
{
	t_dlink *nxt;
	t_dlink *prv;
	t_dlink *new;

	t_dlink *nw;

	nw = src->where;
	src->where->next->prev = src->where->prev;
	src->where->prev->next = src->where->next;
	src->where = src->where->next;
	src->length--;

	nxt = dst->where;
	prv = dst->where->prev;

	new = nw;

	new->next = nxt;
	nxt->prev = new;

	new->prev = prv;

	prv->next = new;

	dst->where = new;
	dst->length += 1;
	o(dst->where);

}

void ft_pa(t_pw *pw)
{
	if (pw->lst_b->length == 0)
		return;
	else if (pw->lst_a->length == 0)
		empty(pw->lst_a, pw->lst_b);
	else if (pw->lst_b->length == 1)
		one(pw->lst_a, pw->lst_b);
	else
		mv(pw->lst_a, pw->lst_b);
}

void ft_pb(t_pw *pw)
{
	if (pw->lst_a->length == 0)
		return;
	else if (pw->lst_b->length == 0)
		empty(pw->lst_b, pw->lst_a);
	else if (pw->lst_a->length == 1)
		one(pw->lst_b, pw->lst_a);
	else
		mv(pw->lst_b, pw->lst_a);
}