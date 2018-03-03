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

t_dll_l add_begin_dll(t_dll dll, void *content, size_t size)
{
	t_dll_l link;
	t_dll_l tmp;

	if (dll->uu.check_data(content, size) == FALSE)
		return (NULL);
	link = new_double_linkedlist_link(content, size);
	if (dll->head == NULL)
		dll->tail = link;
	else
	{
		tmp = dll->head;
		tmp->prev = link;
		link->next = tmp;
	}
	dll->head = link;
	dll->length += 1;
	return (link);
}