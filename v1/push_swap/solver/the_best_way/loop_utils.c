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

int next_bigger(t_loop *l, t_dlink *link)
{
	return (l->nb > gn(link->next));
}

int prev_smaller(t_loop *l, t_dlink *link)
{
	return (l->nb > gn(link->prev));
}

int next_smaller(t_loop *l, t_dlink *link)
{
	return (!next_bigger(l,link));
}

int end_lst(t_loop *l, size_t count)
{
	return (count >= l->lst->length);
}

int nb_bigger(t_loop *l, t_dlink *link)
{
	return (l->nb > gn(link));
}

int nb_lower(t_loop *l, t_dlink *link)
{
	return (!nb_bigger(l,link));
}

/*
**    return nb is biggest that all the nb in the lst
*/

int nb_is_bigest(t_dlink *tmp, t_loop *loop)
{
	return (tmp == loop->lst->head && loop->nb > gn(loop->lst->head));
}

/*
**    return nb is the lowest in all the nb in the lst
*/

int nb_is_lowest(t_dlink *tmp, t_loop *loop)
{
	return (tmp == loop->lst->tail && loop->nb < gn(loop->lst->tail));
}