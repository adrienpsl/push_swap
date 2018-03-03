#ifndef PUSH_SWAP_PILE_H
# define PUSH_SWAP_PILE_H

#include "../../header/header_link_projet.h"

/*
**    structure
*/
typedef struct		s_stack
{
	t_dll_c 		pile_a;
	t_dll_c 		pile_b;
}					*t_stack;

/*
**    method
*/
void destroy_stack(t_stack *s);
t_stack new_stack();

/*
**    modif de pile ==================================================
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




#endif
