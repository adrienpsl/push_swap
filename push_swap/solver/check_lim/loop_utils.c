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

int next_bigger(t_loop *l)
{
	return (gn(l->lst->head) > gn(l->lst->head->next));
}

int prev_smaller(t_loop *l)
{
	return (gn(l->lst->head) > gn(l->lst->head->prev));
}

int next_smaller(t_loop *l)
{
	return (!next_bigger(l));
}

int end_lst(t_loop *l, size_t count)
{
	return (count >= l->lst->length);
}

int nb_bigger(t_loop *l)
{
	return (l->nb > gn(l->lst->head));
}

int nb_lower(t_loop *l)
{
	return (!nb_bigger(l));
}
