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


/*
**    v2
*/
int whose_the_best(t_dll_c list_a);

int get_med(t_dll_c c_list, size_t lenght);

void browse_pile_a(t_stack stack, int max, size_t lim, int option);

/*
**    method commun
*/
void check_and_apply_instruct(char *str, t_stack stack);

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
find_up_down(t_dll_l link, int researched_nb, t_dll_l top_link, t_stack stack);
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

#endif //PUSH_SWAP_ALL_INCLUDES_H
