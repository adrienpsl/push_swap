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

// une f pour aller a au bonne index en checkant le nb a chaque fois
void put_good_nb(t_dlist *lst, int nb)
{
	t_dlink *link;
	t_dlink *new;

	link = lst->head;
	while (link && nb <= *(int*)link->content)
	{
		if (nb == *(int*)link->content)
			ft_error_pw();
		link = link->next;
	}
	if ((new = ft_dlist_link_new(&nb, sizeof(int))) == FAIL)
		ft_exit_lack_memory();
	if (lst->length == 0)
	{
		if (ft_dlst_add_end(lst,&nb,sizeof(int)) == FAIL)
			ft_exit_lack_memory();
		return ;
	}
	new->next = link;
	new->prev = link->prev;
	new->prev->prev = new;

};

//une f pour check si je suis dans le
