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

int manage_split(char *str, char **out)
{
	static char **tab = NULL;
	static char **tab_start = NULL;

	if (tab_start == NULL)
	{
		tab = ft_strsplit(str, ' ');
		tab_start = tab;
	}
	if (*tab != NULL)
	{
		*out = *tab;
		tab++;
		return (TRUE);
	}
	ft_free_split(&tab_start);
	tab = NULL;
	tab_start = NULL;
	return (FALSE);
}

int get_argv_list_a(int ac, char **av, char **out)
{
	static int split = 1;
	static int i = 1;

	if (i < ac)
	{
		if (split == 1 || ft_strchr(av[i], ' '))
		{
			if (split == 0)
				i++;
			split = 1;
			if (manage_split(av[i], out) == FALSE)
				split = 0;
			return (TRUE);
		}
		*out = av[i];
		i++;
		return (TRUE);
	}
	return (FALSE);
}

int main(int ac, char **av)
{
	char *out;
	while (get_argv_list_a(ac, av, &out))
	{;
		ft_printf("%s \n",out);
	}
	return (1);
}

t_dll_c get_list_a(int ac, char **av)
{
	t_dll_c c_list;
	t_dll_l link;
	t_data data;
	char *out;
//	char *cur_av;

	c_list = new_dll_c();
	while (get_argv_list_a(ac, av, &out) == TRUE)
	{
		data = ft_malloc_protect(sizeof(struct s_data));
		ft_memset(data, 0, sizeof(struct s_data));
//		data->nb = is_valide_number(cur_av, c_list);
		link = new_dll_l(data, sizeof(struct s_data));
		dll_c_add_after(link, c_list);
		free(data);
	}
	return (c_list);
}
