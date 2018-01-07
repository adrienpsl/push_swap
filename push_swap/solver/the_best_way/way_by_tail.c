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

int prev_bigger(t_loop *l, t_dlink *link)
{
	return (!prev_smaller(l, link));
}

/*
**    return true if nb is biggest that nb in list
*/

static int big(t_loop *loop)
{
	return (loop->nb > gn(loop->lst->head));
}

/*
**    return true if nb is lowest that nb in list
*/

static int low(t_loop *loop)
{
	return (loop->nb < gn(loop->lst->tail));
}

/*
**    return the number of operation
*/

static long get_result(t_dlink *tmp, t_dlink *tmp2)
{
	long count;

	count = 0;
	while(tmp2 != tmp)
	{
		tmp2  = tmp2->prev;
		count++;
	}
	return (count);
}

long way_by_tail(t_loop *loop)
{
	int a;
	t_dlink *tmp;
	t_dlink *tmp2;

	a = 0;
	tmp2 = loop->lst->where;
	if (!big(loop) && !low(loop))
	{
		tmp = loop->lst->head;
		while (prev_bigger(loop,tmp) && end_lst(loop,a) == FALSE)
		{
			tmp = tmp->prev;
			a++;
		}
	}
	if (big(loop))
		tmp = loop->lst->tail;
	if (low(loop))
		tmp = loop->lst->tail;
	return (get_result(tmp,tmp2));
}
