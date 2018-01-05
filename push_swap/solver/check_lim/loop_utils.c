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


int under_limit(size_t count, t_dlist *lst)
{
	return (count < lst->length);
}


int nb_bigger_head(t_solver *s, t_dlist *lst)
{
	return (s->nb > gn(lst->head));
}

int prev_smaller(t_dlist *lst)
{
	return (gn(lst->head) > gn(lst->head->prev));
}

int next_smaller(t_dlist *lst)
{
	return (gn(lst->head) > gn(lst->head->next));
}