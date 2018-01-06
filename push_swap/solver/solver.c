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

/*
**    avance du bon nombre de nb pour placer 
*/
//static void loop_nb(t_pw *pw, t_solver *s, void (*fun)(t_pw *pw))
//{
//	printf("============== \n");
//	pl(pw->lst_b);
//	while (s->index)
//	{
//		fun(pw);
//		pl(pw->lst_b);
//		s->index--;
//	}
//}
//




static void pp(t_pw *pw)
{
	printf(" la head est %d \n", gn(pw->loop.lst->head));
	printf(" la queue est %d \n", gn(pw->loop.lst->tail ));
}

void put_in_b_ordered(t_pw *pw)
{
	size_t pos_in_a;

	pos_in_a = 0;
	ft_memset(&pw->loop, 0, sizeof(t_loop));
	while (pos_in_a <= pw->lst_a->length)
	{
		g_nb(&pw->loop.nb, pw->lst_a);
		pw->loop.lst = pw->lst_b;
		pos_in_a += find_best_way(pw);
//		do_op(pw);
		pp(pw);
		pll(pw);
	}
}

void ft_solver(t_pw *pw)
{
	put_in_b_ordered(pw);
}