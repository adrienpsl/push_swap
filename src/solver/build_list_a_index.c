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

#include "../../header/all_includes.h"

static size_t get_index_tab(int nb, t_dll list)
{
	size_t index;
	t_dll_l link;

	link = list->top;
	index = 0;
	while (nb != dll_l_get_int(link))
	{
		++index;
		link = link->next;
	}
	return (index);
}

static void set_index(t_dll_c c_list, t_dll quicks_list)
{
	size_t i;
	t_dll_l link;
	int index;

	i = 0;
	link = c_list->top;
	while (i < c_list->length)
	{
		index = get_index_tab(dll_l_get_int(link), quicks_list);
		*(int *) link->content = index;
		link = link->next;
		++i;
	}
}

int get_med(t_dll_c c_list, size_t lenght)
{
	t_dll list;
	t_dll_l link;
	size_t half_lenght;
	size_t i;

	list = new_dll();
	dll_fill_list_circular(c_list, list, lenght);
	ft_quick_sort_dll(list->top, list->end, list);

	i = 0;
	half_lenght = lenght / 2;
	link = list->top;

	while (i < half_lenght)
	{
		link = link->next;
		++i;
	}
	i = dll_l_get_int(link);
	destroy_dll(&list);
	return (i);
}

/*
**    creer la liste et change les nb par leur index definitif
*/
void build_lst_a_index(t_dll_c c_list)
{
	t_dll list;

	list = new_dll();
	dll_fill_list_circular(c_list, list, c_list->length);

	ft_quick_sort_dll(list->top, list->end, list);

	set_index(c_list, list);
	dll_c_print_lst(c_list);
	destroy_dll(&list);
}