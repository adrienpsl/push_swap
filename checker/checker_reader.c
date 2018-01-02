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
		if (nb == *(int *)link->content)
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

t_dlist *ft_checker_reader(int ac, char **av)
{
	t_dlist *lst;
	long i;

	i = 1;
	if ((lst = ft_new_dlst()) == FAIL)
		ft_exit_lack_memory();
	while (i < ac && ft_is_all_number(av[i]) == TRUE)
	{
		put_into_lst(lst, av[i]);
		i++;
	}
	return (lst);
}