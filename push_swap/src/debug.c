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

#include "../includes/all_includes.h"

void	print_quick(t_dll_c lst)
{
	ssize_t i;
	t_dll_l link;

	link = lst->top;
	i = lst->length;
	if (lst->length == 0)
		return ;
	while (i != -1)
	{
		ft_printf("%2d ", get_quick(link));
		i--;
		if (i == 0)
			ft_printf(" -- ");
		link = link->next;
	}
	ft_printf(" \n");
}

void	print_stack(t_stack stack)
{
	ft_printf("\n\n------------------------------------------- \n");
	ft_printf("A :");
	dll_c_print_lst(stack->pile_a);
	ft_printf("   ");
	print_quick(stack->pile_a);
	ft_printf(" \n");
	ft_printf("B :");
	dll_c_print_lst(stack->pile_b);
	ft_printf("   ");
	print_quick(stack->pile_b);
	ft_printf(" \n");
	ft_printf("%d \n", stack->count);
}

void	dll_print_str2(t_dll lst)
{
	t_dll_l link;

	link = lst->top;
	while (link)
	{
		ft_printf("%s", link->content);
		link = link->next;
	}
}
