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

static size_t get_index_tab(int nb, int *tab)
{
	size_t index;

	index = 0;
	while (nb != tab[index])
	{
		++index;
	}
	return (index);
}

static void set_index(t_dll_c c_list, int *tab)
{
	size_t i;
	t_dll_l link;
	int index;

	i = 0;
	link = c_list->top;
	while (i < c_list->length)
	{
		index = get_index_tab(dll_l_get_int(link), tab);
		*(int *) link->content = index;
		link = link->next;
		++i;
	}
}

int *get_fill_tab(t_dll_c list, size_t length)
{
	int *tab;
	size_t lim;
	t_dll_l link;

	link = list->top;
	lim = 0;
	tab = ft_malloc_protect(length);
	ft_memset(tab, 0, sizeof(int) * length);
	while (lim < length)
	{
		tab[lim] = dll_l_get_int(link);
		lim += 1;
		link = link->next;
	}
	return (tab);
}

int get_med(t_dll_c c_list, int length)
{
	int a;
	int *tab;

	tab = get_fill_tab(c_list, length);
	ft_quick_sort(tab, 0, length);

	a = tab[length / 2];
	return (a);
}

/*
**    creer la liste et change les nb par leur index definitif
*/
void build_lst_a_index(t_dll_c c_list)
{
	int *tab;

	tab = get_fill_tab(c_list, c_list->length);

	debug_print_tab_nb(tab, c_list->length);
	ft_quick_sort(tab, 0, c_list->length - 1);
	debug_print_tab_nb(tab, c_list->length);

	set_index(c_list, tab);
	dll_c_print_lst(c_list);

	free(tab);
}