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

#include "../../../../header/all_includes.h"

static void fill_nb(t_dll_l link, int *nb, t_dll_l top_link, int *nb_top)
{
	*nb = get_int_ddl_l(link);
	*nb_top = get_int_ddl_l(top_link);
}

int link_is_bigger_prev(t_dll_l link, t_dll_l top_link)
{
	int nb;
	int nb_prev;

	fill_nb(link, &nb, top_link->prev, &nb_prev);
	return (nb < nb_prev);
}

int link_is_lower_top(t_dll_l link, t_dll_l top_link)
{
	int nb;
	int nb_top;

	fill_nb(link, &nb, top_link, &nb_top);
	return (nb > nb_top);
}

int current_is_the_biggest(t_dll_l link_top, t_stack stack)
{
	int nb_top;
	int max_lim;

	nb_top = get_int_ddl_l(link_top);
	max_lim = stack->max_lim;

	return (nb_top == max_lim);
}

int top_is_research_nb(int researched_nb, t_dll_l top_link)
{
	int top_nb;

		top_nb = get_int_ddl_l(top_link);
	return (researched_nb == top_nb);
}
