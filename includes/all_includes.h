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

#ifndef ALL_INCLUDES_H
# define ALL_INCLUDES_H

# define X_WINDOW 2500
# define Y_WINDOW 2500

# include "../lib/libft/ft_library_header.h"
# include "push_struct.h"
# include "struct_visu.h"
# include "../lib/mlx/mlx.h"
# include <limits.h>

typedef int int___;

typedef void void__;
	
void__		create_graf_link(t_stack stack);
void__		push_instruc_list(char *int______ruct, t_stack stack);
int___		get_med(t_dll_c c_list, int___ length);
void__		need_swap(t_stack stack);
void__		browse_pile_a(t_stack stack, size_t lim);
int___		get_median_push(t_dll_c origin, t_browse *browse, int___ med, int___ op);
int___		*get_fill_tab(t_dll_c list, size_t length);
void__		browse_push(t_stack stack, int___ nb_top_pile);
void__		ft_putnbr_str(int___ n, char *str);
t_v			new_visu(int___ x, int___ y, char *name);
void__		test_visu(t_stack stack);
void__		set_stack_visu(t_stack stack);
void__		do_inst(char raw_instruction, int___ option, t_stack stack);
void__		fill_pixel(char *img, long x, long y, int___ color);
void__		sort_3_top(t_stack stack);
void__		sort_3_end(t_stack stack);
void__		manage_all_short(t_stack stack);
void__		sort_4_end(t_stack stack);
void__		sort_4_top(t_stack stack);
void__		browser_inverse(t_stack stack, size_t med, size_t lim);
void__		check_and_apply_instruct(char *str, t_stack stack);
void__		browser_reverse(t_stack stack, size_t med, size_t lim);
void__		get_med_quick(t_stack stack);
int___		reset_quick_1(t_stack stack);
void__		sort_3_fuck_little(t_stack stack);
void__		first_passage_a(t_stack stack);
void__		brain_is_beauty(t_stack stack);
int___		s_ordered(t_dll_c c_list, size_t lenght);
int___		reset_quick(t_stack stack);
int___		get_quick(t_dll_l link);
void__		set_quick(t_stack stack);
void__		set_quick_1(t_stack stack);
long		count_quick(t_stack stack);
void__		update_quick(t_stack stack);
void__		sort_2_top(t_stack stack);
void__		sort_2_end(t_stack stack);
void__		quick_get_good_pile(t_stack stack);
void__		placed_quick_by_sort(t_stack stack);
void__		get_med_quick_rev(t_stack stack);
void__		sort_browser(t_stack stack, size_t med, size_t lim);
void__		sort_browser_reverse(t_stack stack, size_t med, size_t lim);
t_dll_c		get_list_a(t_argv argv, int___ is_solver);
int___ 		is_valide_number(char *nb_str, t_dll_c c_liste);
void__		exit_wrong_nb(void);
int___		is_action(char *str);
void__		set_stack(char name_pile, t_stack stack);
void__		destroy_stack(t_stack *s);
t_stack		new_stack();
t_stack		get_stack_filled(t_argv argv);
void__		sa(t_stack pile);
void__		sb(t_stack pile);
void__		ss(t_stack pile);
void__		pa(t_stack pile);
void__		pb(t_stack pile);
void__		ra(t_stack pile);
void__		rb(t_stack pile);
void__		rr(t_stack pile);
void__		rra(t_stack pile);
void__		rrb(t_stack pile);
void__		rrr(t_stack pile);
void__		the_legende(t_mlx_data mlx_data, t_rec_link rec, t_fig_2 fig2);
void__		build_lst_a_index(t_dll_c c_list);
void__		do_instruct(char *instruc, t_stack stack);
void__		print_stack(t_stack stack);
void__		print_quick(t_dll_c lst);
void__		recangle(t_fig_2 fig2, t_mlx_data mlx_data);
void__		trace_legend_rec(t_fig_2 fig2, t_mlx_data visu, t_rec_link rec);
long		is_color(t_dll color_list, int___ quick);
t_dll_l		new_color_link(int___ quick, long color);
int___		is_same_quick(t_dll_l color_link, int___ quick);
void__		set_color(t_dll_l color_link, long color);
t_dll		get_list_rec(t_dll_c pile, t_dll color_pile);
void__		print_list(t_v visu, int___ x, int___ mode);

#endif //PUSH_SWAP_ALL_INCLUDES_H
