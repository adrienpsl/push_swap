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

void ft_rra(t_pw *pw)
{
	if (pw->lst_a->where)
	pw->lst_a->where = pw->lst_a->where->prev;
}

void ft_rrb(t_pw *pw)
{
	if (pw->lst_b->where)
		pw->lst_b->where = pw->lst_b->where->prev;
}

void ft_rrr(t_pw *pw)
{
	ft_rra(pw);
	ft_rrb(pw);
}