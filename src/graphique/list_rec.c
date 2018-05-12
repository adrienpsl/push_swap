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

t_dll_l			new_rec_link()
{
	t_dll_l			visu_link;
	t_rec_link_00	rec;
	t_rec_link		rec_link;

	visu_link = new_dll_l(&rec, sizeof(t_rec_link_00));
	ft_memset(visu_link->content, 0, sizeof(t_rec_link_00));
	rec_link = visu_link->content;
	rec_link->max = INT_MIN;
	rec_link->min = INT_MAX;
	return (visu_link);
}

static void		set_rec(t_rec_link rec, t_dll_l link)
{
	rec->nb_quick++;
	if (dll_l_get_int(link) > rec->max)
		rec->max = dll_l_get_int(link);
	if (dll_l_get_int(link) < rec->min)
		rec->min = dll_l_get_int(link);
}

t_dll_l			fill_rec_link(t_dll_c pile, int *quick, long size_pile)
{
	t_dll_l		rec_link;
	t_rec_link	rec;

	*quick = get_quick(pile->top);
	if (pile->length != 0)
	{
		rec_link = new_rec_link();
		while (pile->length && get_quick(pile->top) == *quick)
		{
			rec = rec_link->content;
			set_rec(rec, pile->top);
			pile->top = pile->top->next;
			pile->length--;
		}
	}
	else
		return (NULL);
	rec->percent = (float) rec->nb_quick / size_pile;
	rec->quick = *quick;
	return (rec_link);
}

t_dll			get_list_rec(t_dll_c pile, t_dll color_pile)
{
	t_dll_l		rec_link;
	t_dll_c		pile_copy;
	t_dll		rec_pile;
	int			quick;

	pile_copy = new_dll_c();
	rec_pile = new_dll();
	pile_copy->top = pile->top;
	pile_copy->length = pile->length;
	while ((rec_link = fill_rec_link(pile_copy, &quick, pile->length)) != FALSE)
	{
		set_color(rec_link,
				  is_color(color_pile, quick));
		dll_add(rec_link, rec_pile);
	}
	free(pile_copy);
	return (rec_pile);
}
