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

#include "../push_swap.h"

static void put_good_nb(t_dlist *lst, int nb)
{
	t_dlink *link;

	link = lst->head;
	while (link)
	{
		if (nb == *(int *) link->content)
			ft_error_ck();
		link = link->next;
	}
	ft_dlst_add_end(lst, &nb, sizeof(int));
};

static void put_into_lst(t_dlist *lst, char *data)
{
	long nb;

	nb = ft_atol(data);
	if (nb < INT_MIN || nb > INT_MAX)
		ft_error_ck();
	put_good_nb(lst, nb);
}

int get_number(int ac, char **av, t_dlist *lst)
{
	long i;

	i = 1;
	while (i < ac && ft_is_all_number(av[i]) == TRUE)
	{
		put_into_lst(lst, av[i]);
		i++;
	}
	lst->where = lst->head;
	make_circle(lst);
	return (i);
}

int get_number_single(char **av, t_dlist *lst)
{
	while (*av && ft_is_all_number(*av) == TRUE)
	{
		put_into_lst(lst, *av);
		av++;
	}
	lst->where = lst->head;
	make_circle(lst);
	return (2);
}

int ft_checker_reader(t_pw *pw, int ac, char **av, int *i)
{

	if ((pw->lst_a = ft_new_dlst()) == FAIL)
		ft_exit_lack_memory();
	if ((pw->lst_b = ft_new_dlst()) == FAIL)
		ft_exit_lack_memory();
	if (ft_strchr(av[1], ' '))
		*i = get_number_single(ft_strsplit(av[1], ' '), pw->lst_a);
	else
		*i = get_number(ac, av, pw->lst_a);
	return (DONE);
}