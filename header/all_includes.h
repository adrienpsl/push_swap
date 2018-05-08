#ifndef PUSH_SWAP_ALL_INCLUDES_H
#define PUSH_SWAP_ALL_INCLUDES_H

# define X_WINDOW 2000
# define Y_WINDOW 1500


# include "../src/sources/ft_library_header.h"
# include "push_struct.h"
# include "struct_visu.h"
# include "../mlx/mlx.h"
# include <limits.h>

int get_med(t_dll_c c_list, int length);

void need_swap(t_stack stack);

void browse_pile_a(t_stack stack, size_t lim);

int get_median_push(t_dll_c origin, t_browse *browse, int med, int op);
int *get_fill_tab(t_dll_c list, size_t length);

void browse_push(t_stack stack, int nb_top_pile);

/*
**    namage instruc
*/
void do_inst(char raw_instruction, int option, t_stack stack);

void med2(t_stack stack);
void get_min_max(t_dll_l link, size_t length, t_stack stack);
/*
**    short 3
*/
void sort_3_top(t_stack stack);
void sort_3_end(t_stack stack);
void manage_all_short(t_stack stack);

void sort_4_end(t_stack stack);
void sort_4_top(t_stack stack);

void browser_inverse(t_stack stack, size_t med, size_t lim);
/*
**    method commun
*/
void check_and_apply_instruct(char *str, t_stack stack);

void browser_reverse(t_stack stack, size_t med, size_t lim);

void get_med_quick(t_stack stack);

int reset_quick_1(t_stack stack);
void sort_3_fuck_little(t_stack stack);

/*
**    quick
*/
int reset_quick(t_stack stack);
int get_quick(t_dll_l link);
void set_quick(t_stack stack);
void set_quick_1(t_stack stack);
long count_quick(t_stack stack);
void update_quick(t_stack stack);

void sort_2_top(t_stack stack);
void sort_2_end(t_stack stack);

void quick_get_good_pile(t_stack stack);
void placed_quick_by_sort(t_stack stack);

int is_ordered(t_dll_c c_list, size_t lenght);

void get_med_quick_rev(t_stack stack);

void sort_browser(t_stack stack, size_t med, size_t lim);
void sort_browser_reverse(t_stack stack, size_t med, size_t lim);

/*
**    method get_number
*/
t_dll_c get_list_a(t_argv argv, int is_solver);
int is_valide_number(char *nb_str, t_dll_c c_liste);
void exit_wrong_nb();
int is_action(char *str);

/*
**    method stack
*/
void set_stack(char name_pile, t_stack stack);
void destroy_stack(t_stack *s);
t_stack new_stack();
t_stack get_stack_filled(t_argv argv);

/*
**    modif de stack ==================================================
*/
void sa(t_stack pile);
void sb(t_stack pile);
void ss(t_stack pile);
void pa(t_stack pile);
void pb(t_stack pile);
void ra(t_stack pile);
void rb(t_stack pile);
void rr(t_stack pile);
void rra(t_stack pile);
void rrb(t_stack pile);
void rrr(t_stack pile);

/*
**    solver =============================================================
*/
void build_lst_a_index(t_dll_c c_list);

/*
**    method instruct
*/
void do_instruct(char *instruc, t_stack stack);

/*
**    debug
*/
void print_stack(t_stack stack);
void print_quick(t_dll_c lst);

/*
**    graphique
*/
void recangle(t_fig_2 fig2, t_mlx_data mlx_data);

void trace_legend_rec(t_fig_2 fig2, t_mlx_data visu, t_rec_link rec);

long is_color(t_dll color_list, int quick);
t_dll_l new_color_link(int quick, long color);
int is_same_quick(t_dll_l color_link, int quick);
void set_color(t_dll_l color_link, long color);
t_dll get_list_rec(t_dll_c pile, t_dll color_pile);
void print_list(t_visualisateur visu, int x);

#endif //PUSH_SWAP_ALL_INCLUDES_H
