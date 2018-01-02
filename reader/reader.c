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

#include "../push_swap/push_swap.h"

static void put_into_lst(t_dlist *lst, char *data)
{
	long nb;

	if (ft_is_all_number(data) == FALSE)
		ft_error_pw();
	nb = ft_atol(data);
	if (nb < INT_MIN || nb > INT_MAX)
		ft_error_pw();
	put_good_nb(lst, nb);
	if ((ft_dlst_add_end(lst, &nb, sizeof(int))) == FAIL)
		ft_exit_lack_memory();
}

static void single_str(t_dlist *lst, char *str)
{
	char **data;

	if ((data = ft_strsplit(str, ' ')) == FAIL)
		ft_exit_lack_memory();
	while (*data)
	{
		put_into_lst(lst, *data);
		data++;
	}
	ft_free_doublechar_tab(&data);
}

static void get_argv(t_dlist *lst, int ac, char **av)
{
	long i;

	i = 1;

	while (i < ac)
	{
		put_into_lst(lst, av[i]);
		i++;
	}
}

t_dlist *ft_main_reader(int ac, char **av)
{
	t_dlist *lst;

	if ((lst = ft_new_dlst()) == FAIL)
		ft_exit_lack_memory();
	if (ac == 2)
		single_str(lst, av[1]);
	else
		get_argv(lst, ac, av);
	return (lst);
}
