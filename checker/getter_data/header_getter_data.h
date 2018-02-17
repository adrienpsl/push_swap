#ifndef PUSH_SWAP_GETTER_DATA_CONSTRUC_H
#define PUSH_SWAP_GETTER_DATA_CONSTRUC_H

#include "../checker.h"

/*
**    ==== define the type of my object ======================================
*/
typedef struct s_getter *t_getter;

/*
**    ==== methods ===========================================================
*/
typedef struct s_m_getter
{
	int (*is_valide_number)(t_getter getter, char *nb_str);
	void (*exit_wrong_nb)();
	t_dll (*get_lst_a)(t_getter getter);
	void (*destroy)(t_getter *);
} t_m_getter;



/*
**    ==== define my object ==================================================
*/

struct s_getter
{
	t_m_getter mm;
	t_dll pile_a;
	t_argv argv;
};

/*
**    ==== prototype method ==================================================
*/
int is_a_valid_number(char* str, int *nb_out);
void exit_wrong_nb();


/*
**    ==== prototype debug ===================================================
*/

/*
**    ==== utils =============================================================
*/


/*
**    ==== prototype constructor =============================================
*/
t_getter new_getter(t_argv arg);
int is_valide_number(t_getter getter, char *nb_str);
t_dll get_lst_a(t_getter getter);

#endif



