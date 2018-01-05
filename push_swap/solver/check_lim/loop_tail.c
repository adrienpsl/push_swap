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



size_t loop_taller_tail(t_solver *s, t_dlist *l)
{
	size_t count;

	count = 0;
	while (nb_bigger_head(s, l) == TRUE
		   && under_limit(count, l) == TRUE
		   && prev_smaller(l) == TRUE)
	{
		count++;
		l->head = l->head->prev;
	}
	if (nb_bigger_head(s, l) == TRUE && under_limit(count, l) == TRUE)
		count++;
	while (nb_bigger_head(s, l) == FALSE && under_limit(count, l) == TRUE)
	{
		count++;
		l->head = l->head->prev;
	}
	return (count);
}

size_t loop_smaller_tail(t_solver *s, t_dlist *l)
{
	size_t count;
	int a;
	int b;
	count = 0;
	phead(l);
	while (nb_bigger_head(s, l) == FALSE && under_limit(count, l) == TRUE)
	{
		count++;
		l->head = l->head->prev;
		phead(l);
		a = *(int *) l->head->content;
		b = *(int *) l->head->prev->content;
		if (prev_smaller(l) == FALSE)
		{
			printf("count = %zu  head = %d prev = %d\n",count, a,b );
			s->more = 1;
			break;
		}
	}
	while (nb_bigger_head(s, l) == TRUE && under_limit(count, l) == TRUE)
	{
		count++;
		l->head = l->head->prev;
		phead(l);
		a = *(int *) l->head->content;
		b = *(int *) l->head->prev->content;
		if (prev_smaller(l) == )
		{
			printf("count = %zu  head = %d prev = %d\n",count, a,b );
			s->more = 1;
			break;
		}
	}
	return (count);
}