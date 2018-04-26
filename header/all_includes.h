#ifndef PUSH_SWAP_ALL_INCLUDES_H
#define PUSH_SWAP_ALL_INCLUDES_H

# include "../sources/ft_library_header.h"
# include "push_struct.h"
# include <limits.h>

#define SEARCH 1
#define APPLY_BY_TOP 2
#define APPLY_BY_BOTTOM 3
#define LIST_A 1
#define LIST_B 2
#define DEVANT_DERRIERE 1

#define PILE_A 1
#define PILE_B 2

#define TOP_PUSH 2
#define END_PUSH 3

# define FORCE_OP 10
# define NO_OP 12
/*
**    v2
*/
int whose_the_best(t_dll_c list_a);

int get_med(t_dll_c c_list, int length);

void need_swap(t_stack stack);

void set_brower(int med, size_t lim, int option, t_stack stack);
int browse_pile(t_stack stack, t_browse *browse);
void browse_pile_a(t_stack stack, t_browse *browse, size_t remaining);

/*
**    namage instruc
*/
void do_inst(char raw_instruction, int option, t_stack stack);


/*
**    short 3
*/
void sort_3_top(t_stack stack);
void sort_3_front_b(t_stack stack);
void sort_3_end(t_stack stack);

/*
**    all short
*/
void set_index_sort_algo(t_dll_c pile_1, size_t size);
void do_ab_front_a(t_stack stack);
void sort_4_a(char *tab, t_stack stack);
void sort_top_4_b(char *tab, t_stack stack);


void sort_4_end(t_stack stack);
void sort_4_top(t_stack stack);


void sort_4_end_a(t_stack stack);

/*
**    short_4
*/
void sort_4(t_stack stack);
void do_ab(t_stack stack);
void is_abab(t_stack stack);
void is_abba(t_stack stack);
void is_bbaa(t_stack stack);
void is_aabb(t_stack stack);
void is_baba(t_stack stack);
void is_baab(t_stack stack);


void browser_inverse(t_stack stack, size_t med, size_t lim, int need_quick);
/*
**    method commun
*/
void check_and_apply_instruct(char *str, t_stack stack);


void browser(t_stack stack, size_t med, size_t lim, int need_quick);
void browser_reverse(t_stack stack, size_t med, size_t lim, int need_quick);
//void browser_quick(t_stack stack, size_t med, size_t lim, int need_quick);

void to_4(t_stack stack);
void get_med_quick(t_stack stack);
/*
**    quick
*/
int reset_quick(t_stack stack);
int get_quick(t_dll_l link);
void set_quick(t_stack stack);
void set_quick_1(t_stack stack);
long count_quick(t_stack stack);
void placed_quick(t_dll_l link, size_t lim);
void update_quick(t_stack stack);

void sort_2_top(t_stack stack);
void sort_2_end(t_stack stack);

void quick_get_good_pile(t_stack stack);
void placed_quick_by_sort(t_stack stack);

int is_ordered(t_dll_c c_list, size_t lenght);
int is_ordered_link(t_dll_l link, size_t lenght);



void sort_4(t_stack stack);
void get_med_quick_rev(t_stack stack);
/*
**    short 4 top a
*/
void sort_4_top_a(char *tab, t_stack stack);
void abab_sort4top_a(t_stack stack);
void baab_sort4top_a(t_stack stack);
void abba_sort4top_a(t_stack stack);
void baba_sort4top_a(t_stack stack);

/*
**    short 4 top b
*/
void sort_4_top_b(char *tab, t_stack stack);
void abab_sort4top_b(t_stack stack);
void baab_sort4top_b(t_stack stack);
void abba_sort4top_b(t_stack stack);
void baba_sort4top_b(t_stack stack);


void a_4(t_stack stack);
void b_4(t_stack stack);
void b_3(t_stack stack);
void get_ab(t_stack stack);

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
void put_by_top_orbuttom(t_stack stack);

/*
**    trouve s'il est plus pertinent d'aller par le top ou le bas de la stack
**    pour depenser le moins possible de coup
*/
long
find_up_down(t_dll_l link, int researched_nb, t_dll_l top_link,
 t_stack stack);
void do_the_ops_pileb(t_stack stack, long operations);
void do_the_ops_pilea(t_stack stack, long nb_operations);

void nb_is_limit(t_stack stack);
void nb_isnt_limit(t_stack stack);

/*
**    put_by_top_or_buttom
*/
int link_is_bigger_top(t_dll_l link, t_dll_l top_link);
int link_is_lower_top(t_dll_l link, t_dll_l top_link);
int current_is_the_biggest(t_dll_l link_top, t_stack stack);

int is_normal(t_stack stack, int mode);
int is_biggest_lowest(t_stack stack, int mode);
int top_is_research_nb(int researched_nb, t_dll_l top_link);

void push_in_b(t_stack stack);

/*
**    method instruct
*/
void do_instruct(char *instruc, t_stack stack);

/*
**    debug
*/
void p_tab(int tab[], int limit);
void get_median(t_stack stack, int occurs, int is_the_last);
void print_stack(t_stack stack);
void print_quick(t_dll_c lst);

#endif //PUSH_SWAP_ALL_INCLUDES_H
