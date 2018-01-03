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

#include "../../libft/includes/src/libft_d_lst_function.h"


void pl(t_dlist *l)
{
	size_t i;
	t_dlink *tmp;

	i = 0;
	tmp = l->where;
	printf("[[ ");
	while(i < l->length)
	{
		printf("%d, ", *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	printf("]] \n");
}
