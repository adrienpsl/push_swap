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

static t_dll_l get_link_by_index(t_dll dll, size_t index)
{
	t_dll_l link;

	if (index == 0)
		return (dll->head);
	if (index >= dll->length)
		return (dll->tail);
	link = dll->head;
	while (index)
	{
		link = link->next;
		index -= 1;
	};
	return (link);
}

static t_dll_l two_link(t_dll dll, t_dll_l link)
{
	t_dll_l remaining_link;

	remaining_link = (link == dll->head) ? dll->tail : dll->head;
	remaining_link->mm.reset_ptr(remaining_link);
	link->mm.reset_ptr(link);
	dll->head = remaining_link;
	dll->tail = remaining_link;
	return (link);
}

static t_dll_l one_link(t_dll dll)
{
	t_dll_l link;

	link = dll->head;
	(void)"=== set a 0 dll ====";
	dll->head = NULL;
	dll->where = NULL;
	dll->tail = NULL;
	link->mm.reset_ptr(link);
	return (link);
}

static t_dll_l more_two_links(t_dll dll, t_dll_l link)
{
	t_dll_l prev;
	t_dll_l next;

	prev = link->prev;
	next = link->next;
	(void)"                ";
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	(void)"                ";
	if (dll->head == link)
		dll->head = link->next;
	else if (dll->tail == link)
		dll->tail = link->prev;
	(void)"                ";
	link->mm.reset_ptr(link);
	return (link);
}

t_dll_l drop_link_dll(t_dll dll, size_t index, t_dll_l link_given)
{
	t_dll_l link;
	t_dll_l dropped_link;

	if (dll->length == 0)
		return (NULL);
	else if (dll->length == 1)
		dropped_link = one_link(dll);
	else
	{
		link = link_given ? link_given : get_link_by_index(dll, index);

		if (dll->length == 2)
			dropped_link = two_link(dll, link);
		else
			dropped_link = more_two_links(dll, link);
	}
	dll->length -= 1;
	return (dropped_link);
}