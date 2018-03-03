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

/*
**    exit if no argv given
*/
void no_argv(char *string, int ac)
{
	if (ac < 2)
	{
		ft_putstr_fd(string, 2);
		exit(42);
	}
}

static int is_one(t_argv argv)
{
	return (argv->ac - argv->count == 1);
}

static void destroy(t_argv *argv)
{
	free(*argv);
	*argv = NULL;
}

static void init_method(t_argv argv)
{
	argv->mm.destroy = &destroy;
	argv->mm.is_one = &is_one;
}

t_argv new_argv(int ac, char **av)
{
	t_argv argv;

	argv = ft_malloc_protect(sizeof(struct s_argv));
	init_method(argv);
	argv->ac = ac;
	argv->av = av;
	argv->count = 1;
	ft_memset(argv->str_options, 0, SIZE_OPTION);
	return (argv);
}