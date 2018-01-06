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

// une fonction pour mettre a head ou tail au bon endroit


// une f pour check head ou tail si mon nb est inferiereu == put
// s'il est supeieur == put
static int nb_is_bigest(t_dlink *tmp, t_loop *loop)
{
	return (tmp == loop->lst->head && loop->nb > gn(loop->lst->head));
}

static int nb_is_lowest(t_dlink *tmp, t_loop *loop)
{
	return (tmp == loop->lst->tail && loop->nb < gn(loop->lst->tail));
}

static int good_place(t_loop *loop)
{
	return (next_smaller(loop) && nb_lower(loop));
}

/*
**	return the nb of operation for put the nb into b_lst,
**	the head and the tail are the borne max and min of the b_lst
*/

size_t nb_taller_head(t_loop *loop)
{
	size_t count;
	t_dlink *tmp;

	count = 0;
	tmp = loop->lst->where;
//	plt(tmp,loop->lst);
	while (end_lst(loop, count) == FALSE)
	{
		if (good_place(loop))
			break;
		if (nb_is_bigest(tmp, loop))
		{
			(count += 1);
			break;
		}
		if (nb_is_lowest(tmp, loop))
			break;
		tmp = tmp->next;
		plt(tmp, loop->lst);
		count += 1;
	}

	return (count >= loop->lst->length ? 0 : count);
}
