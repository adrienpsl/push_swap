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

static int fit(int nb, t_pw *pw)
{
	if (nb >= pw->lim.med)
		return (RIGHT);
	return (KEEP_LEFT);
}

static void do_op(int op, t_pw *pw)
{
	if (op == RIGHT)
		ft_pb(pw);
	if (op == KEEP_LEFT)
		ft_sa(pw);
}

void ft_solver(t_pw *pw)
{
	int a;
	while (a < pw->lst_a->length)
	{
		Dfit;
	}
}