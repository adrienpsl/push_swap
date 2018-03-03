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

static t_dll_l one_link(t_dll ddl)
{
	t_dll_l link;

	link = ddl->where;
	ddl->where = NULL;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static t_dll_l more_one_links(t_dll ddl)
{
	t_dll_l next;
	t_dll_l prev;
	t_dll_l link;

	link = ddl->where;
	next = link->next;
	prev = link->prev;
	(void)"                           ";
	prev->next = next;
	next->prev = prev;
	link->prev = NULL;
	link->next = NULL;
	ddl->where = next;
	return (link);
}

t_dll_l drop_link_circular(t_dll dll)
{
	t_dll_l link;

	if (dll->length == 0)
		return (NULL);
	else if (dll->length == 1)
		link = one_link(dll);
	else
		link = more_one_links(dll);
	dll->length -= 1;
	return (link);
}
