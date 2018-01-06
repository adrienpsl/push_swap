/* ************************************************************************** *//*

*/
/*                                                                            *//*

*/
/*                                                        :::      ::::::::   *//*

*/
/*   ft_atoi.c                                          :+:      :+:    :+:   *//*

*/
/*                                                    +:+ +:+         +:+     *//*

*/
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        *//*

*/
/*                                                +#+#+#+#+#+   +#+           *//*

*/
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             *//*

*/
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       *//*

*/
/*                                                                            *//*

*/
/* ************************************************************************** *//*


#include "../../../push_swap.h"

size_t loop_taller_tail(t_solver *s, t_dlist *l)
{
	size_t count;
	int a;
	int b;

	count = 0;
	while (end_lst(count, l) == TRUE)
	{
		count++;
		l->head = l->head->prev;
		if (nb_bigger_head(s,l) == FALSE && prev_smaller(l) == FALSE)
			break;
	}
	return (count);
	phead(l);
	a = *(int *) l->head->content;
	b = *(int *) l->head->prev->content;
}

size_t loop_smaller_tail(t_solver *s, t_dlist *l)
{
	size_t count;

	count = 0;
	while (end_lst(count, l) == TRUE)
	{
		count++;
		l->head = l->head->prev;
		if (nb_bigger_head(s,l) == FALSE && prev_smaller(l) == FALSE)
			break;
	}
	return (count);
}*/
