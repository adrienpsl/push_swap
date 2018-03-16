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

#include "../../../../header/all_includes.h"

static void save_instruct_in_strack(char *instruct, t_stack stack)
{
	t_dll_l link;

	link = new_dll_l(instruct, ft_strlen(instruct));
	dll_c_add_after(link, stack->instruction);
}

void do_instruct(char *instruc, t_stack stack)
{
	check_and_apply_instruct(instruc, stack);
	save_instruct_in_strack(instruc,stack);
	printf("%s ",instruc);
}