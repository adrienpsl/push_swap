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

t_dll_c			get_list_a(t_argv argv)
{
	t_dll_c	c_list;
	t_dll_l	link;
	t_data	data;
	char	*cur_av;

	c_list = new_dll_c();
	while (argv_get(&cur_av, argv) == TRUE)
	{
		data = ft_malloc_protect(sizeof(struct s_data));
		ft_memset(data, 0, sizeof(struct s_data));
		data->nb = is_valide_number(cur_av, c_list);
		link = new_dll_l(data, sizeof(struct s_data));
		dll_c_add_after(link, c_list);
		free(data);
	}
	return (c_list);
}
