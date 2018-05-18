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

#ifndef PUSH_SWAP_PUSH_STRUCT_H
# define PUSH_SWAP_PUSH_STRUCT_H

# include "all_includes.h"
# include "struct_visu.h"

typedef struct		s_get_ar
{
	char			**tab;
	int				size_tab;
	int				i;
	char			*out;
	int				split;
}					t_get_ar;

typedef struct		s_med
{
	size_t			mediane;
	size_t			medianne_push;

}					t_med;

typedef struct		s_browse
{
	size_t			lim;
	size_t			option;
	size_t			pile;
	size_t			quick_count;
}					t_browse;

typedef struct		s_quick
{
	int				quick;
	int				counter_quick;
	char			sens;
}					t_quick;

typedef struct		s_stack_visu_00
{
	t_dll			pile_a;
	t_dll			pile_b;
}					t_stack_visu_00;
typedef t_stack_visu_00 *t_stack_visu;

/*
**    structure
*/

typedef struct		s_stack
{
	t_v				visu;
	t_dll_c			pile_a;
	t_dll_c			pile_b;
	t_dll			list_instruc;
	char			current_pile;
	t_dll_c			currrent_pile_dll;
	char			last_instruct[5];
	int				count;
	t_browse		browse;
	t_quick			quick;
	t_med			med;
	char			*argv;
	t_dll			v_data;
	t_dll			color_tmp;
}					t_stack_00;
typedef t_stack_00 *t_stack;

typedef struct		s_data
{
	int				nb;
	int				quick;
	char			n;
}					t_data_00;
typedef t_data_00 *t_data;

#endif
