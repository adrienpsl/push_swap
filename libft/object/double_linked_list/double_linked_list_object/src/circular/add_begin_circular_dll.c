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

#define EMPTY 0

static t_dll_l list_empty(t_dll dll, t_dll_l link)
{
	dll->where = link;
	link->next = link;
	link->prev = link;
	return (link);
}

static t_dll_l list_no_empty(t_dll dll, t_dll_l link)
{
	t_dll_l prev;
	t_dll_l next;

	prev = dll->where->prev;
	next = dll->where;
	(void)"                                          ";
	link->next = next;
	next->prev = link;
	(void)"                                          ";
	link->prev = prev;
	prev->next = link;

	return (link);
}

t_dll_l add_begin_circular_dll(t_dll dll, void *content, size_t size, t_dll_l l)
{
	t_dll_l link;

	if (dll->uu.check_data(content, size) == FALSE && l == NULL)
		return (NULL);
	if (l != NULL)
		link = l;
	else
		link = new_double_linkedlist_link(content, size);
	if (dll->length == EMPTY)
		list_empty(dll, link);
	else
		list_no_empty(dll, link);
	dll->length += 1;
	return (link);

}