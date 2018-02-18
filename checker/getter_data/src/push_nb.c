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

static void av_need_ft_split(t_getter getter, char ***av,
 int *need_free, unsigned int *nb_count)
{
	t_argv argv;

	argv = getter->argv;
	if (ft_strchr(argv->av[1], ' '))
	{
		*av = ft_strsplit(argv->av[1], ' ');
		*nb_count = nb_argv_split(*av);
		argv->count += 1;
		*need_free = 1;
	}
	else
	{
		*av = argv->av;
		*nb_count = UINT_MAX;
		*need_free = 0;
	}
}

static void build_list_a(t_getter getter, unsigned int nb_count,
 char **av, int is_split)
{
	int i;
	int nb;
	t_dll pile_a;

	i = is_split ? 0 : 1;
	pile_a = getter->pile_a;
	while (i < nb_count)
	{
		if (is_argv(av[i]))
			break;
		nb = getter->mm.is_valide_number(getter, av[i]);
		pile_a->cc.circular_add_begin(pile_a, &nb, sizeof(int), NULL);
		i++;
	}
	getter->argv->count =  is_split ? 2 : i;
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
	unsigned int nb_count;
	t_dll pile_a;

	av_need_ft_split(getter, &av, &need_free, &nb_count);
	build_list_a(getter, nb_count, av, need_free);
	pile_a = getter->pile_a;
	if (need_free)
		ft_free_split(&av);
	return (pile_a);
}