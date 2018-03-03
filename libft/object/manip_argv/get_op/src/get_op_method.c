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

#include "../../header_manip_argv.h"
#include "../header/header_get_op.h"

static int is_same_str(char *s1, char **options)
{
	while (*options != NULL)
	{
		if (ft_strcmp(s1, *options) == 0)
			return (TRUE);
		options++;
	}
	return (FALSE);
}

static int limit_av(int a, int b)
{
	return (a < b);
}

t_argv get_option_proto(t_get_op get_op)
{
	t_argv argv;

	argv = get_op->argv;

	if (argv->ac <= 1)
		return (argv);
	while (1
		   && limit_av(argv->count, argv->ac)
		   && is_same_str(argv->av[argv->count], get_op->options))
	{
		ft_charcat(argv->str_options, argv->av[argv->count][1]);
		argv->count++;
	}
	return (argv);
}