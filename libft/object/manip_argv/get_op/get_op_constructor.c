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

#include "../header_manip_argv.h"
#include "header/header_get_op.h"

static void destroy_argv(t_get_op *get_op)
{

	ft_free_split(&(*get_op)->options);
	free(*get_op);
	*get_op = NULL;
}

static void init_method(t_get_op argv)
{
	argv->mm.destroy = &destroy_argv;
	argv->mm.get_option = &get_option_proto;
}

t_get_op new_get_op(int ac, char **av)
{
	t_get_op get_op;

	get_op = ft_malloc_protect(sizeof(struct s_get_op));
	init_method(get_op);
	get_op->argv = new_argv(ac, av);
	get_op->options = ft_strsplit(OPTIONS, ' ');
	return (get_op);
}
