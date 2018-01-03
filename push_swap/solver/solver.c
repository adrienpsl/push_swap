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

static void check_lim_right(t_solver *s, t_pw *pw)
{
	if (s->nb <= pw->lim.fst)
		s->op = RIGHT_UP;
	else
		s->op = RIGHT_DOWN;
}

//static void check_lim_r(t_solver *s, t_pw *pw)
//{
//	if (s->nb <= pw->lim.fst)
//		s->op = RIGHT_UP;
//	else
//		s->op = RIGHT_DOWN;
//}

static void check_lim(t_solver *s, t_pw *pw)
{
	if (s->nb <= pw->lim.med)
		check_lim_right(s, pw);
	else
		s->op = KEEP_LEFT;
}

static void do_op(int op, t_pw *pw)
{
	if (op == RIGHT_DOWN)
		ft_pb(pw);
	else if (op == RIGHT_UP)
	{
		ft_pb(pw);
		ft_rb(pw);
	}
	else if (op == KEEP_LEFT)
		ft_ra(pw);
}

void ft_solver(t_pw *pw)
{
	t_solver s;

	ft_memset(&s, 0, sizeof(t_solver));
	make_circle(pw->lst_a);
	while (s.i < pw->lst_a->length)
	{
		g_nb(&s.nb, pw->lst_a);
		check_lim(&s, pw);
		do_op(s.op, pw);
		pll(pw);
		s.i += s.op < RIGHT ? 1 : 0;
	}
}