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

#include "../../checker.h"

//char **(t_getter getter)
//{
//
//};
static int inline_argv(t_argv argv)
{
	return (argv->ac - argv->count == 1);
}

static int nb_argv_split(char **tab)
{
	int i;

	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	return (i);
}

static void av_need_ft_split(t_getter getter, char ***av, int *need_free)
{
	t_argv argv;

	argv = getter->argv;
	if (inline_argv(argv))
	{
		*av = ft_strsplit(argv->av[1], ' ');
		*need_free = nb_argv_split(*av);
		argv->count = 0;
		argv->ac -= 2;
	}
	else
	{
		*av = argv->av;
		*need_free = 0;
	}
	getter->argv->ac += *need_free;
}

static void build_list_a(t_getter getter, char **av)
{
	int i;
	int nb;
	t_argv argv;
	t_dll pile_a;

	argv = getter->argv;
	i = argv->count;
	pile_a = getter->pile_a;
	argv = getter->argv;
	while (i < argv->ac)
	{
		nb = getter->mm.is_valide_number(getter, av[i]);
		pile_a->cc.circular_add_begin(pile_a, &nb, sizeof(int), NULL);
		i++;
	}
}

/*
**	  si je met //	getter->pile_a->cc.print_circular_nb(pile_a, ' ');
**    ca ne print pas les nombres dans une fonction qui la recupere, je ne sais
**    pas pk c'est super bizarre !!
*/

t_dll get_lst_a(t_getter getter)
{
	char **av;
	int need_free;
	t_dll pile_a;

	av_need_ft_split(getter, &av, &need_free);
	build_list_a(getter, av);
	pile_a = getter->pile_a;
	if (need_free)
		ft_free_split(&av);
	return (pile_a);
}