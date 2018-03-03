#ifndef PUSH_SWAP_GETTER_DATA_CONSTRUC_H
#define PUSH_SWAP_GETTER_DATA_CONSTRUC_H

#include "header_link_projet.h"


t_dll_c get_list_a(t_argv argv, int is_solver);

/*
**    method ===================================================================
*/
int is_valide_number(char *nb_str, t_dll_c c_liste);

/*
**    utils ====================================================================
*/
void exit_wrong_nb();
int is_action(char *str);

#endif



