#ifndef PUSH_SWAP_PUSH_STRUCT_H
#define PUSH_SWAP_PUSH_STRUCT_H

#include "all_includes.h"

typedef struct		s_browse
{
	size_t		lim;
	size_t		stop;
	size_t		option;
	size_t		med;
	size_t		pile;
	size_t 		median_push;
	size_t 		count;
	size_t		browse_size;
	size_t		quick_count;
} 					t_browse;


typedef struct		s_quick
{
	int 	quick;
	int 	counter_quick;
} 					*t_quick;
/*
**    structure
*/
typedef struct		s_stack
{
	t_dll_c pile_a;
	t_dll_c pile_b;

	size_t	median_junp;
	size_t	mediane_up;
	size_t	mediane_down;
	char 	instruct[3];

	// sont pour le push in b car pas le meme si limit or not limit
	int max_lim;
	int min_lim;

	t_sll instruction;
	t_dll_c temp_instuct;
	int count;
	size_t nb_already_sorted;
	t_browse browse;
	t_quick  quick;

} 					*t_stack;


typedef struct		s_data
{
	int		nb;
	int 	quick;
	int 	short_;
	char 	n;
} 					*t_data;

#endif
