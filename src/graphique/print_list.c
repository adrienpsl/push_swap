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

#include "../../header/all_includes.h"



void set_set(t_dll_l visu_link, t_fig_2 fig2)
{
	t_rec_link rec;

	rec = visu_link->content;
	fig2->color = rec->color;

	fig2->y_2 += (rec->percent * Y_WINDOW);
}

void print_list(t_visualisateur visu, int x)
{
	t_dll_l rec_link;
	t_fig_2_00 fig2;
	t_rec_link rec;

	rec_link = visu->rec_pile->top;
	fig2.x_1 = x;
	fig2.x_2 = x + 150;
	fig2.y_2 = 0;
	fig2.y_1 = 0;

	while (rec_link)
	{
		rec = rec_link->content;
		set_set(rec_link, &fig2);
		//		trace_legend_rec(&fig2, test->visu, rec_link->content);
		trace_legend_rec(&fig2, &visu->mlx_data, (t_rec_link)rec_link->content);
		fig2.y_1 = fig2.y_2;
		rec_link = rec_link->next;
	}
}



void set_(int a, int b, t_dll_c pile)
{
	t_dll_l link_create;
	t_wrong_link_00 op;

	op.nb = a;
	op.quick = b;
	link_create = new_dll_l(&op, sizeof(t_wrong_link_00));
	dll_c_add_after(link_create, pile);
}

//int main()
//{
//	//	t_fig_2 fig2;
//
//	t_visualisateur visu;
//	visu = new_visu(300, SIZE_WINDOW_Y, "push_push");
//
//	visu->pile_a = new_dll_c();
//	t_dll_c pile = visu->pile_a;
//
//	set_(0, 1, pile);
//	set_(5, 1, pile);
//	set_(15, 1, pile);
//	set_(455, 1, pile);
//	set_(4, 1, pile);
//	set_(4, 1, pile);
//
//	set_(684, 3, pile);
//	set_(88, 3, pile);
//	set_(88, 3, pile);
//
//	set_(88, 4, pile);
//	set_(88, 4, pile);
//	set_(88, 4, pile);
//
//	set_(88, 5, pile);
//	set_(88, 5, pile);
//	set_(88, 5, pile);
//
//	set_(88, 6, pile);
//	set_(88, 6, pile);
//	set_(88, 6, pile);
//
//	set_(88, 7, pile);
//	set_(88, 7, pile);
//	set_(88, 7, pile);
//
//	set_(88, 8, pile);
//	set_(88, 8, pile);
//	set_(88, 8, pile);
//
//	set_(88, 9, pile);
//	set_(88, 9, pile);
//	set_(88, 9, pile);
//	//	set_(354, 3, pile);
//
//	dll_c_print_lst(pile);
//
//	visu->rec_pile = get_list_rec(visu->pile_a, visu->list_color);
//
//	dll_c_print_lst(pile);
//	//	print_list(p_visu, &test, pile);
//
//	print_list(visu, 50);
//
//	mlx_loop(visu->mlx_data.mlx);
//}