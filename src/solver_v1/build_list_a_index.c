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

static void fill_tab(t_dll_c c_list, int *tab)
{
	size_t i;
	t_dll_l link;

	i = 0;
	link = c_list->top;
	while (i < c_list->length)
	{
		tab[i] = get_int_ddl_l(link);
		link = link->next;
		++i;
	}
}

static size_t get_index_tab(int nb, int *tab)
{
	size_t index;

	index = 0;
	while (tab[index] != nb)
	{
		++index;
	}
	return (index);
}

static void set_index(t_dll_c c_list, int *tab)
{
	size_t i;
	t_dll_l link;

	i = 0;
	link = c_list->top;
	while (i < c_list->length)
	{
		*(int *) link->content = get_index_tab(get_int_ddl_l(link), tab);
		link = link->next;
		++i;
	}
}
/*
**    creer la liste et change les nb par leur index definitif
*/
void build_lst_a_index(t_dll_c c_list)
{
	int *tab;

	tab = ft_malloc_protect(sizeof(int) * (c_list->length + 1));
	fill_tab(c_list, tab);
	ft_quick_sort(tab, 0, c_list->length - 1, c_list->length - 1);
	set_index(c_list, tab);
	free(tab);
}