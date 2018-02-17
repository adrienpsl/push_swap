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

void ft_ra(t_pw *pw)
{
	if(pw->lst_a->where)
	pw->lst_a->where = pw->lst_a->where->next;
}

void ft_rb(t_pw *pw)
{
	if(pw->lst_b->where)
	pw->lst_b->where = pw->lst_b->where->next;
}

void ft_rr(t_pw *pw)
{
	ft_ra(pw);
	ft_rb(pw);
}