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
static void loop_nb(t_pw *pw, t_solver *s, void (*fun)(t_pw *pw))
{
	printf("============== \n");
	pl(pw->lst_b);
	while (s->index)
	{
		fun(pw);
		pl(pw->lst_b);
		s->index--;
	}
}

static int one_el(t_pw *pw, t_solver *s)
{
	ft_pb(pw);
	if (s->nb < *(int*)pw->lst_b->where->next->content)
		ft_rb(pw);
	return (DONE);
}

static int put_nb(t_pw *pw, t_solver *s)
{
	if ((s->op == UP || s->op == DOWN) && s->index >= pw->lst_b->length)
		return one_el(pw, s);
	else if (s->op == UP)
		loop_nb(pw, s, &ft_rb);
	else if (s->op == DOWN)
		loop_nb(pw, s, &ft_rrb);
	else if (s->op == ONE)
		return (one_el(pw, s));
	if (s->op != KEEP_LEFT)
		ft_pb(pw);
	return (DONE);
}

void ft_solver(t_pw *pw)
{
	t_solver s;

	ft_memset(&s, 0, sizeof(t_solver));
	while (s.i < pw->lst_a->length)
	{
		g_nb(&s.nb, pw->lst_a);
		check_lim(&s, pw);
		put_nb(pw, &s);
		pll(pw);
	}
}