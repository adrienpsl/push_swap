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

#include "../../includes/all_includes.h"

int count_split(char **tab)
{
	int i;

	i = 0;
	while (*tab)
	{
		tab++;
		i++;
	}
	return (i);
}

void set_ar(int ac, char **av, t_get_ar *ar)
{
	ft_memset(ar, 0, sizeof(t_get_ar));
	ar->split = ft_strchr(av[1], ' ') ? TRUE : FALSE;
	if (ar->split)
	{
		ar->tab = ft_strsplit(av[1], ' ');
		ar->size_tab = count_split(ar->tab);
	}
	else
	{
		ar->tab = av;
		ar->size_tab = ac;
		ar->i = 1;
	}
}

int get_argv_list_a(t_get_ar *ar)
{
	if (ar->i < ar->size_tab)
	{
		ar->out = ar->tab[ar->i];
		ar->i++;
		return (TRUE);
	}
	if (ar->split)
		ft_free_split(&ar->tab);
	return (FALSE);
}

t_dll_c get_list_a(int ac, char **av)
{
	t_dll_c c_list;
	t_dll_l link;
	t_data data;
	t_get_ar ar;

	c_list = new_dll_c();
	set_ar(ac, av, &ar);
	while (get_argv_list_a(&ar) == TRUE)
	{
		data = ft_malloc_protect(sizeof(struct s_data));
		ft_memset(data, 0, sizeof(struct s_data));
		data->nb = is_valide_number(ar.out, c_list);
		link = new_dll_l(data, sizeof(struct s_data));
		dll_c_add_after(link, c_list);
		free(data);
	}
	return (c_list);
}
