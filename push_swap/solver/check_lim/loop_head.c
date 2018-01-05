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



size_t loop_taller_head(t_solver *s, t_dlist *l)
{
	size_t count;

	count = 0;
	while (nb_bigger_head(s, l) == TRUE
		   && under_limit(count, l) == TRUE
		   && next_smaller(l) == TRUE)
	{
		count++;
		l->head = l->head->next;
	}
	if (nb_bigger_head(s, l) == TRUE && under_limit(count, l) == TRUE)
		count++;
	while (nb_bigger_head(s, l) == FALSE && under_limit(count, l) == TRUE)
	{
		count++;
		l->head = l->head->next;
	}
	return (count);
}

size_t loop_smaller_head(t_solver *s, t_dlist *l)
{
	size_t count;

	count = 0;
	while (nb_bigger_head(s, l) == FALSE && under_limit(count, l) == TRUE)
	{
		count++;
		if (next_smaller(l) == FALSE)
			break;
		l->head = l->head->next;
	}
	return (count);
}