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

#include "../../../double_linked_list.h"

void circular_destroy_ddl(t_dll *l)
{
	t_dll_l link_head;
	t_dll_l link_tail;
	t_dll dll;

	dll = *l;
	if (dll->length > 0)
	{
		link_head = dll->where;
		link_tail = dll->where->prev;
		link_head->prev = NULL;
		link_tail->next = NULL;
		dll->head = link_head;
	}
	dll->mm.destroy(l);
}