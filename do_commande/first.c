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

static void mv(t_dlist *lst)
{
	int tmp;

	if (lst->length == 1 && lst->length == 0)
		return ;
	tmp = *(int*)lst->where->content;
	*(int*)lst->where->content = *(int*)lst->where->next->content;
	*(int*)lst->where->next->content = tmp;
}

void ft_sa(t_pw *pw)
{
	mv(pw->lst_a);
}

void ft_sb(t_pw *pw)
{
	mv(pw->lst_b);
}

void ft_ss(t_pw *pw)
{
	ft_sa(pw);
	ft_sb(pw);
}