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

#include "../../../header/all_includes.h"

void sort_2_top(t_stack stack)
{
	do_inst('p', NO, stack);
	do_inst('p', NO, stack);
	need_swap(stack);
}

void sort_2_end(t_stack stack)
{
	do_inst('a', NO, stack);
	do_inst('a', NO, stack);
	sort_2_top(stack);
}