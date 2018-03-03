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

#define HEAD 1

static t_dll_l check_index(t_dll dll, void *content, size_t size, size_t index)
{
	if (index == 0)
		return (add_begin_dll(dll, content, size));
	if (index >= dll->length)
		return (add_end_dll(dll, content, size));
	return (NULL);
}

static int head_or_tail(size_t size_list, size_t index)
{
	return (index < size_list / 2);
}

static t_dll_l link_at_good_index(t_dll dll, size_t index)
{
	size_t i;
	t_dll_l link;

	if (head_or_tail(dll->length, index) == HEAD)
	{
		link = dll->head;
		i = 0;
		while (i != index)
		{
			link = link->next;
			i++;
		}
	}
	else
	{
		link = dll->tail;
		i = dll->length;
		while (i != index)
		{
			link = link->prev;
			i--;
		}
	}
	return (link);
}

static t_dll_l insert_link(t_dll_l prev, t_dll_l new_link)
{
	t_dll_l next;

	next = prev->next;
	new_link->prev = prev;
	prev->next = new_link;
	(void)1;
	new_link->next = next;
	next->prev = new_link;
	return (new_link);
}

/*
**    add like  : the list is -- 0 1 2 3-- I set index = 2, 8 i'll get 0 1 8 2 3
*/

t_dll_l add_at_index_dll(t_dll dll, void *content, size_t size, size_t index)
{
	t_dll_l link_at_index;
	t_dll_l new_link;

	if (dll->uu.check_data(content, size) == FALSE)
		return (NULL);
	if (index == 0 || index >= dll->length)
		return (check_index(dll, content, size, index));
	link_at_index = link_at_good_index(dll, index);
	new_link = new_double_linkedlist_link(content, size);
	return (insert_link(link_at_index, new_link));
}