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

int *get_tab(t_pw *pw)
{
	int *tab;
	t_dlink *link;
	size_t i;

	link = pw->lst_a->head;
	i = 0;
	if ((tab = (int*)malloc(sizeof(int) * pw->lst_a->length + 1)) == FAIL)
		ft_exit_lack_memory();
	tab[pw->lst_a->length] = 0;
	while (i <= pw->lst_a->length)
	{
		tab[i] = *(int*)link->content;
		link = link->next;
		i++;
	}
	return (tab);
}

void	ft_error_pw(void)
{
	ft_putstr("Error\n");
	exit(42);
}
