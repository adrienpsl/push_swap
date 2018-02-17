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

	while (gn(link) == gn(link->prev) - 1)
	{
		link = link->prev;
	}
	printf("%d \n", gn(link));
}

/*
**    check si a est ordonner :
 *
*/

void pass_atob_by_pivot(t_pw *pw)
{
	size_t pos_in_a;

	pos_in_a = 0;
	ft_memset(&pw->loop, 0, sizeof(t_loop));
	while (pos_in_a < pw->lst_a->length &&
		   pw->lst_a->where != pw->lim_tail)
	{
		get_nbtop_stack_lst(&pw->loop.nb, pw->lst_a);
		pw->loop.lst = pw->lst_b;
		pos_in_a += find_best_way(pw);
	}
	is_ranger(pw->lst_b);
}

// remettre b dans a

long the_best_way(t_dlist *lst)
{
	t_dlink *tmp;
	long count_head;
	long count_tail;

	count_head = 0;
	count_tail = 0;
	tmp = lst->where;
	while (tmp != lst->head)
	{
		count_head++;
		tmp = tmp->next;
	}
	tmp = lst->where;
	while (tmp != lst->head)
	{
		count_tail++;
		tmp = tmp->prev;
	}
	return (count_head > count_tail ? count_tail * -1 : count_head);
}

void put_b_in_a(t_pw *pw)
{
	long count;

	printf("----------%d \n", gn(pw->lim_head));
	printf("----------%d \n", gn(pw->lim_tail));
	pll(pw, "before lim head");
	if (pw->lim_head)
	{
		while (pw->lst_a->where != pw->lim_head)
		{
			ft_ra(pw);
		}
		ft_ra(pw);
	}
	pll(pw, "after lim head");
	count = the_best_way(pw->loop.lst);
	while (count > 0)
	{
		ft_rb(pw);
		count--;
	}
	while (count < 0)
	{
		ft_rrb(pw);
		count++;
	}
	pw->lim_head = pw->lst_b->where;
	while (pw->lst_b->where)
	{
		ft_pa(pw);
	}
	pw->lim_tail = pw->lst_a->where;
	pll(pw, "emd =====");
}

void go_head(t_pw *pw)
{
	long count;

	count = gn(pw->lim_head);
	while (count >= -1)
	{
		ft_rra(pw);
		count--;
	}
}

/*
**    manage les fonctions qui trie un passade des nb
*/
void ft_solver(t_pw *pw)
{
	pass_atob_by_pivot(pw);
	put_b_in_a(pw);
	go_head(pw);
	pll(pw,"relauchn =============");
}