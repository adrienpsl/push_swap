/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:53 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libft.h"

void	ft_lst_reverse(t_list **l)
{
	t_list	*lst;
	t_list	*l1;
	t_list	*l2;

	lst = *l;
	if (!lst->next)
		return ;
	l1 = lst->next;
	l2 = l1->next;
	lst->next = NULL;
	l1->next = lst;
	while (l2)
	{
		lst = l1;
		l1 = l2;
		l2 = l2->next;
		l1->next = lst;
	}
	*l = l1;
}
