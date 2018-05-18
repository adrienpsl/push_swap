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

typedef int		t_int___;
typedef void	t_void__;

void			dll_print_str2(t_dll lst);
int				check(char *s, void *ptr);
t_void__		create_graf_link(t_stack stack);
t_void__		push_instruc_list(char *t_int______ruct, t_stack stack);
t_int___		get_med(t_dll_c c_list, t_int___ length);
t_void__		need_swap(t_stack stack);
t_void__		browse_pile_a(t_stack stack, size_t lim);
t_int___		get_median_push(t_dll_c origin, t_browse *browse, t_int___ med,
		t_int___ op);
t_int___		*get_fill_tab(t_dll_c list, size_t length);
t_void__		browse_push(t_stack stack, t_int___ nb_top_pile);
t_void__		ft_putnbr_str(t_int___ n, char *str);
t_v				new_visu(t_int___ x, t_int___ y, char *name);
t_void__		test_visu(t_stack stack);
t_void__		set_stack_visu(t_stack stack);
t_void__		do_inst(char raw_instruction, t_int___ option, t_stack stack);
t_void__		fill_pixel(char *img, long x, long y, t_int___ color);
t_void__		sort_3_top(t_stack stack);
t_void__		sort_3_end(t_stack stack);
t_void__		manage_all_short(t_stack stack);
t_void__		sort_4_end(t_stack stack);
t_void__		sort_4_top(t_stack stack);
t_void__		browser_inverse(t_stack stack, size_t med, size_t lim);
t_void__		check_and_apply_instruct(char *str, t_stack stack);
t_void__		browser_reverse(t_stack stack, size_t med, size_t lim);
t_void__		get_med_quick(t_stack stack);
t_int___		reset_quick_1(t_stack stack);
t_void__		sort_3_fuck_little(t_stack stack);
t_void__		first_passage_a(t_stack stack);
t_void__		brain_is_beauty(t_stack stack);
t_int___		s_ordered(t_dll_c c_list, size_t lenght);
t_int___		reset_quick(t_stack stack);
t_int___		get_quick(t_dll_l link);
t_void__		set_quick(t_stack stack);
t_void__		set_quick_1(t_stack stack);
long			count_quick(t_stack stack);
t_void__		update_quick(t_stack stack);
t_void__		sort_2_top(t_stack stack);
t_void__		sort_2_end(t_stack stack);
t_void__		quick_get_good_pile(t_stack stack);
t_void__		placed_quick_by_sort(t_stack stack);
t_void__		get_med_quick_rev(t_stack stack);
t_void__		sort_browser(t_stack stack, size_t med, size_t lim);
t_void__		sort_browser_reverse(t_stack stack, size_t med, size_t lim);
t_dll_c			get_list_a(int ac, char **av);
t_int___		is_valide_number(char *nb_str, t_dll_c c_liste);
t_void__		exit_wrong_nb(void);
t_int___		is_action(char *str);
t_void__		set_stack(char name_pile, t_stack stack);
t_void__		destroy_stack(t_stack *s);
t_stack			new_stack();
t_stack			get_stack_filled(int ac, char **av);
t_void__		sa(t_stack pile);
t_void__		sb(t_stack pile);
t_void__		ss(t_stack pile);
t_void__		pa(t_stack pile);
t_void__		pb(t_stack pile);
t_void__		ra(t_stack pile);
t_void__		rb(t_stack pile);
t_void__		rr(t_stack pile);
t_void__		rra(t_stack pile);
t_void__		rrb(t_stack pile);
t_void__		rrr(t_stack pile);
t_void__		the_legende(t_mlx_data mlx_data, t_rec_link rec, t_fig_2 fig2);
t_void__		build_lst_a_index(t_dll_c c_list);
t_void__		do_instruct(char *instruc, t_stack stack);
t_void__		print_stack(t_stack stack);
t_void__		print_quick(t_dll_c lst);
t_void__		recangle(t_fig_2 fig2, t_mlx_data mlx_data);
t_void__		trace_legend_rec(t_fig_2 fig2, t_mlx_data visu, t_rec_link rec);
long			is_color(t_dll color_list, t_int___ quick);
t_dll_l			new_color_link(t_int___ quick, long color);
t_int___		is_same_quick(t_dll_l color_link, t_int___ quick);
t_void__		set_color(t_dll_l color_link, long color);
t_dll			get_list_rec(t_dll_c pile, t_dll color_pile);
t_void__		print_list(t_v visu, t_int___ x, t_int___ mode);

#endif
