#ifndef PUSH_SWAP_PUSH_STRUCT_H
#define PUSH_SWAP_PUSH_STRUCT_H

#include "all_includes.h"

/*
**    structure
*/
typedef struct		s_stack
{
	t_dll_c pile_a;
	t_dll_c pile_b;
	size_t	mediane_up;
	size_t	mediane_down;
	int max_lim;
	int min_lim;
	t_list *instruction;
	t_dll_c temp_instuct;
	int count;
} 					*t_stack;


#endif
