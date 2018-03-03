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

#include "../../double_linked_list.h"

void print_by_head_ddl(t_dll dll, char separateur)
{
	t_dll_l link;

	link = dll->head;
	if (link == NULL)
	{
		printf("list empty \n");
		return;
	}
	while (link)
	{
		printf("%s %c", link->content, separateur);
		link = link->next;
	}
}

void print_by_tail_ddl(t_dll dll,char separateur)
{
	t_dll_l link;

	link = dll->tail;
	if (link == NULL)
	{
		printf("list empty \n");
		return;
	}
	while (link)
	{
		printf("%s %c", link->content,separateur);
		link = link->prev;
	}
}

void print_ddl(t_dll dll, char separateur)
{
	size_t i;
	t_dll_l link;

	i = 0;
	link = dll->where;
	while (i < dll->length)
	{
	    printf("%s%c",link->content, separateur);
		link = link->next;
		i += 1;
	}
}

void print_circular_nb(t_dll dll, char separateur)
{
	size_t i;
	t_dll_l link;

	i = 0;
	link = dll->where;
	while (i < dll->length)
	{
		printf("%d%c",link->mm.get_content_int(link), separateur);
		link = link->next;
		i += 1;
	}
	printf(" \n");
}