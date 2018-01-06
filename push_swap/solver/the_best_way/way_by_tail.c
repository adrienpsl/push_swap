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
**	return nb is bigger that link(highest) all the nb in the lst
**	like lst +     1 > nb > lst
*/

//static int good_place(t_dlink *link, t_loop *l)
//{
//	return (prev_smaller(l, link) && nb_bigger(l, link) &&
//			next_bigger(l, link));
//}
// les biggest ne sont pas bon ...

int big(t_loop *loop)
{
	return (loop->nb > gn(loop->lst->head));
}

int low(t_loop *loop)
{
	return (loop->nb < gn(loop->lst->tail));
}

long way_by_tail(t_loop *loop)
{
	long count;
	int a;
	t_dlink *tmp;
	t_dlink *tmp2;

	count = 0;
	a = 0;
	tmp2 = loop->lst->where;
	tmp = loop->lst->head;
	printf("tail : %d head : %d\n",gn(loop->lst->head), gn(loop->lst->tail) );
	if (!big(loop) && !low(loop))
	{
		tmp = loop->lst->head;
		while (prev_bigger(loop,tmp) && end_lst(loop,a) == FALSE)
		{
			tmp = tmp->prev;
			a++;
		}
//		tmp = tmp->prev;

//		if (nb_bigger(loop,tmp) && tmp->next == loop->lst->head)
//			tmp = tmp->next;
	}
	printf("%d \n", gn(tmp));
	printf("%d \n", gn(tmp2));
	if (big(loop))
		tmp = loop->lst->tail;
	if (low(loop))
		tmp = loop->lst->tail;

	while(tmp2 != tmp)
	{
		tmp2  = tmp2->prev;
		count++;
	}




	//	while (end_lst(loop, count) == FALSE)
	//	{
	//		plt(tmp, loop->lst);
	//		printf("nb = %d   \ntmp =  %d \nprev = %d \n --------- \n",
	//			   loop->nb, gn(tmp), gn(tmp->prev));
	//		if (good_place(tmp, loop))
	//			break;
	//		if (nb_is_bigest(tmp, loop))
	//		{
	//			(count += 1);
	//			break;
	//		}
	//		if (nb_is_lowest(tmp, loop))
	//		{
	//			break;
	//		}
	//		count += 1;
	//		tmp = tmp->prev;
	//	}
	count = (size_t) count >= loop->lst->length ? 0 : count;
	return (count * -1);
}
