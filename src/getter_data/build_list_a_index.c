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

#include "../../includes/all_includes.h"

t_stack		get_stack_filled(t_argv argv)
{
	t_stack stack;

	stack = new_stack();
	stack->pile_a = get_list_a(argv, ACTIVATE);
	return (stack);
}

size_t		get_index_tab(int nb, int *tab)
{
	size_t index;

	index = 0;
	while (nb != tab[index])
	{
		++index;
	}
	return (index);
}

void		set_index(t_dll_c c_list, int *tab)
{
	size_t	i;
	t_dll_l	link;
	int		index;

	i = 0;
	link = c_list->top;
	while (i < c_list->length)
	{
		index = get_index_tab(dll_l_get_int(link), tab);
		*(int *)link->content = index;
		link = link->next;
		++i;
	}
}

int			*get_fill_tab(t_dll_c list, size_t length)
{
	int		*tab;
	size_t	lim;
	t_dll_l	link;

	link = list->top;
	lim = 0;
	tab = ft_malloc_protect(sizeof(int) * length);
	ft_memset(tab, 0, sizeof(int) * (length));
	while (lim < length)
	{
		tab[lim] = dll_l_get_int(link);
		lim += 1;
		link = link->next;
	}
	return (tab);
}

void		build_lst_a_index(t_dll_c c_list)
{
	int *tab;

	tab = get_fill_tab(c_list, c_list->length);
	ft_quick_sort(tab, 0, c_list->length - 1);
	set_index(c_list, tab);
	free(tab);
}
