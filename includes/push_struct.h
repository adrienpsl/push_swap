#ifndef PUSH_SWAP_PUSH_STRUCT_H
#define PUSH_SWAP_PUSH_STRUCT_H

#include "all_includes.h"
#include "struct_visu.h"

typedef struct		s_med
{
	size_t			mediane;
	size_t			medianne_push;

} 					t_med;

typedef struct		s_browse
{
	size_t			lim;
	size_t			option;
	size_t			pile;
	size_t			quick_count;
} 					t_browse;


typedef struct		s_quick
{
	int				quick;
	int				counter_quick;
	char			sens;
} 					t_quick;

typedef struct		s_stack_visu_00
{
	t_dll			pile_a;
	t_dll			pile_b;
} 					t_stack_visu_00;
typedef t_stack_visu_00 *t_stack_visu;

/*
**    structure
*/
typedef struct		s_stack
{
	t_visualisateur	visu;
	t_dll_c			pile_a;
	t_dll_c			pile_b;
	t_dll			list_instruc;
	char			current_pile;
	t_dll_c			currrent_pile_dll;
	char			instruct[4];
	char			last_instruct[4];
	int				count;
	t_browse		browse;
	t_quick			quick;
	t_med			med;
	char			*argv;
	t_dll			v_data;
	t_dll			color_tmp;
}					*t_stack;


typedef struct		s_data
{
	int				nb;
	int				quick;
	char			n;
} 					*t_data;

#endif
