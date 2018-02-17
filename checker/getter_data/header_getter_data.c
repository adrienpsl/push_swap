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

#include "../checker.h"

#include "header_getter_data.h"

static void destroy(t_getter *g)
{
	free(*g);
	*g = NULL;
}

static void init_method(t_getter getter)
{
	getter->mm.destroy = &destroy;
	getter->mm.exit_wrong_nb = &exit_wrong_nb;
	getter->mm.is_valide_number = &is_valide_number;
	getter->mm.get_lst_a = &get_lst_a;
}

t_getter new_getter(t_argv argv)
{
	t_getter getter;

	getter = ft_malloc_protect(sizeof(struct s_getter));
	init_method(getter);

	getter->argv = argv;
	getter->pile_a = new_double_linked_list();

	return (getter);
}