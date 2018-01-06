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

/*
**    return nb is biggest that all the nb in the lst
*/

static int nb_is_bigest(t_dlink *tmp, t_loop *loop)
{
	return (tmp == loop->lst->head && loop->nb > gn(loop->lst->head));
}

/*
**    return nb is the lowest in all the nb in the lst
*/

static int nb_is_lowest(t_dlink *tmp, t_loop *loop)
{
	return (tmp == loop->lst->tail && loop->nb < gn(loop->lst->tail));
}

/*
**	return nb is lower that link(hi) all the nb in the lst
**	like lst - 1 < nb < lst
*/

static int good_place(t_dlink *link, t_loop *l)
{
	return (prev_smaller(l,link) && nb_lower(l,link));
}

/*
**	return the nb of operation for put the nb into b_lst,
**	the head and the tail are the bornes max and min of the b_lst
*/

long nb_taller_head(t_loop *loop)
{
	size_t count;
	t_dlink *tmp;

	count = 0;
	tmp = loop->lst->where;
	while (end_lst(loop, count) == FALSE)
	{
		printf("nb = %d ", loop->nb);
		printf("tmp = %d ", gn(tmp));
		printf("prv = %d \n", gn(tmp->prev));
		if (good_place(tmp,loop))
			break;
		if (nb_is_bigest(tmp, loop))
		{
			if (count == 0)
				return (-1);
			(count += 1);
			break;
		}
		if (nb_is_lowest(tmp, loop))
			break;
		tmp = tmp->next;
		count += 1;
	}
	return (count >= loop->lst->length ? 0 : count);
}
