/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:56 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	if (!(link = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(link->content = malloc(content_size)))
			return (NULL);
		ft_memmove(link->content, content, content_size);
		link->content_size = content_size;
	}
	else
	{
		link->content = NULL;
		link->content_size = 0;
	}
	link->next = NULL;
	return (link);
}
