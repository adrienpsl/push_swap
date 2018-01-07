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

#include "../../push_swap.h"

 void is_ranger(t_dlist *l)
{
	t_dlink *link = l->tail;

	while (gn(link) == gn(link->next) -1)
	    link = link->next;
	printf("%d \n", gn(link));
}

void put_in_b_ordered(t_pw *pw)
{
	size_t pos_in_a;

	pos_in_a = 0;
	ft_memset(&pw->loop, 0, sizeof(t_loop));
	while (pos_in_a < pw->lst_a->length)
	{
		g_nb(&pw->loop.nb, pw->lst_a);
		pw->loop.lst = pw->lst_b;
		pos_in_a += find_best_way(pw);
		pll(pw);
	}
	is_ranger(pw->lst_b);
}


void ft_solver(t_pw *pw)
{
	put_in_b_ordered(pw);

}