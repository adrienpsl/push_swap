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

#include "../double_linked_list.h"

static void destroy_all_links(t_dll_l link)
{
	t_dll_l tmp;

	if (link == NULL)
		return;
	while (link)
	{
		tmp = link;
		link = link->next;
		tmp->mm.destroy(&tmp);
	}
}

static void destroy(t_dll *l)
{
	t_dll list;

	list = *l;
	destroy_all_links(list->head);
	list->tail = NULL;
	list->head = NULL;
	list->where = NULL;
	free(list);
}

static void init_method(t_dll list)
{
	(void) "		init les method								";
	list->mm.destroy = &destroy;
	list->mm.add_begin = &add_begin_dll;
	list->mm.add_end = &add_end_dll;
	list->mm.add_at_index = &add_at_index_dll;
	list->mm.drop_link = &drop_link_dll;
	list->mm.delete_link = &delete_link_dll;
	(void) "                         init les circular methods     ";
	list->cc.circular_destroy = &circular_destroy_ddl;
	list->cc.circular_add_begin = &add_begin_circular_dll;
	list->cc.circular_drop_link = &drop_link_circular;
	list->cc.circular_push = circular_push_dll;
	list->cc.circular_find_by_nb = &circular_find_by_nb;
	list->cc.print_circular_nb = &print_circular_nb;
	(void) "		init les method debug								";
	list->dd.print_by_head = &print_by_head_ddl;
	list->dd.print_by_tail = &print_by_tail_ddl;
	(void) "		init les methods utils			";
	list->uu.check_data = &check_data_ddl;
	list->cc.circular_print = &print_ddl;
}

t_dll new_double_linked_list()
{
	t_dll list;

	list = ft_malloc_protect(sizeof(struct s_dll));
	list->where = NULL;
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	init_method(list);
	return (list);
}
