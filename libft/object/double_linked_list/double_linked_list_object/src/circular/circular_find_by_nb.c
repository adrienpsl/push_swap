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

t_dll_l circular_find_by_nb(t_dll dll, int nb, int (*cmp)(t_dll_l, int))
{
	size_t i;
	t_dll_l link;

	link = dll->where;
	i = 0;
	while (i < dll->length)
	{
		if (cmp(link, nb) == TRUE)
			return (link);
		link = link->next;
		i += 1;
	}
	return (NULL);
}