/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:55 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst)
		return (NULL);
	if (!(new_lst = f(lst)))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if (!(temp = f(lst)))
			return (NULL);
		ft_lstadd(&new_lst, temp);
		lst = lst->next;
	}
	ft_lst_reverse(&new_lst);
	return (new_lst);
}
