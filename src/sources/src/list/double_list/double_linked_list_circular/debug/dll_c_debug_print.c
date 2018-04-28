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

#include "../../../../../ft_library_header.h"

void dll_c_print_lst(t_dll_c lst)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;
	while (i != -1)
	{
		ft_printf("%2d ", dll_l_get_int(link));
		i--;
		if (i == 0)
			break ;
		link = link->next;
	}
	ft_printf("-- %zu \n", lst->length);
	ft_printf(" \n");
}

void dll_c_print_lst_reverse(t_dll_c lst)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;
	while (i != -1)
	{
		ft_printf("%d ", dll_l_get_int(link));
		i--;
		if (i == 0)
			ft_printf(" -- ");
		link = link->prev;
	}
	ft_printf(" \n");
}

void dll_c_print_lst_str(t_dll_c lst)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;
	while (i != -1)
	{
		ft_printf("%s ", link->content);
		i--;
		if (i == 0)
			ft_printf(" -- ");
		link = link->next;
	}
	ft_printf(" \n");
}

void dll_c_print_lst_str_reverse(t_dll_c lst)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;
	while (i != -1)
	{
		ft_printf("%s ", link->content);
		i--;
		if (i == 0)
			ft_printf(" -- ");
		link = link->prev;
	}
	ft_printf(" \n");
}