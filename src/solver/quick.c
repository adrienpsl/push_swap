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

long count_quick(int quick_searched, t_dll_c pile)
{
	long nb_quick_in_pile;
	int current_quick;
	t_dll_l link;
	size_t size;

	nb_quick_in_pile = 0;
	size = 0;
	link = pile->top;
	current_quick = get_quick(link);
	while (current_quick == quick_searched && size < pile->length)
	{
		link = link->next;
		current_quick = get_quick(link);
		nb_quick_in_pile += 1;
		size++;
	}
	return (nb_quick_in_pile);
}


int get_quick(t_dll_l link)
{
	return (((t_data) link->content)->quick);
}

void set_quick(int quick, t_dll_l link)
{
	((t_data)link->content)->quick = quick;
}