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

/*
**	return nb is lower that link(highest) all the nb in the lst
**	like lst - 1 < nb < lst
*/

//static int good_place(t_dlink *link, t_loop *l)
//{
//	return (!prev_smaller(l,link) && !nb_lower(l,link));
//}

/*
**    return the number of operation
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

static long get_result(t_dlink *tmp, t_dlink *tmp2)
{
	long count;

	count = 0;
	while(tmp2 != tmp)
	{
		tmp2  = tmp2->next;
		count++;
	}
	return (count);
}

long way_by_head(t_loop *loop)
{
	int a;
	t_dlink *tmp;
	t_dlink *tmp2;

	a = 0;
	tmp2 = loop->lst->where;
	if (!big(loop) && !low(loop))
	{
		tmp = loop->lst->tail;
		while (prev_smaller(loop,tmp) && end_lst(loop,a) == FALSE)
		{
			tmp = tmp->prev;
			a++;
		}
	}
	if (big(loop))
		tmp = loop->lst->head;
	if (low(loop))
		tmp = loop->lst->head;
	return (get_result(tmp,tmp2));
}


//
///*
//**	return the nb of operation for put the nb into b_lst,
//**	the head and the tail are the bornes max and min of the b_lst
//*/
//
//long way_by_head(t_loop *loop)
//{
//	size_t count;
//	t_dlink *tmp;
//
//	count = 0;
//	tmp = loop->lst->where;
//	while (end_lst(loop, count) == FALSE)
//	{
//		if (good_place(tmp,loop))
//			break;
//		if (nb_is_bigest(tmp, loop))
//		{
//			(count += 1);
//			break;
//		}
//		if (nb_is_lowest(tmp, loop))
//			break;
//		tmp = tmp->next;
//		count += 1;
//	}
//	return (count >= loop->lst->length ? 0 : count);
//}
