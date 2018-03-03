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

#ifndef LIBFT_DOUBLE_LINKED_LIST_HEADER_H
# define LIBFT_DOUBLE_LINKED_LIST_HEADER_H

# include "../../double_linked_list.h"

/*
**    define the type of my object
*/
typedef struct s_dll *t_dll;

/*
**    methods
*/
typedef struct s_m_dll
{
	void (*destroy)(t_dll *);
	void (*delete_link)(t_dll, size_t, t_dll_l);
	t_dll_l (*add_end)(t_dll, void *, size_t);
	t_dll_l (*add_begin)(t_dll, void *, size_t);
	t_dll_l (*add_at_index)(t_dll, void *, size_t, size_t);
	t_dll_l (*drop_link)(t_dll, size_t, t_dll_l link_given);
} t_m_dll;

/*
**    circular method
*/
typedef struct s_c_dll
{
	void (*circular_destroy)(t_dll *dll);
	void (*circular_print)(t_dll dll, char separateur);
	t_dll_l (*circular_drop_link)(t_dll);
	t_dll_l
	(*circular_add_begin)(t_dll dll, void *content, size_t size, t_dll_l l);
	t_dll_l (*circular_push)(t_dll dll, t_dll_l link);
	t_dll_l (*circular_find_by_nb)(t_dll, int, int (*cmp)(t_dll_l, int));
	void (*print_circular_nb)(t_dll dll, char separateur);
} t_c_dll;

/*
**    method debug
*/
typedef struct s_d_dll
{
	void (*print_by_head)(t_dll, char);
	void (*print_by_tail)(t_dll, char);
} t_d_dll;

/*
**    utils
*/
typedef struct s_u_dll
{
	int (*check_data)(void *, size_t);
} t_u_dll;

/*
**    define my object
*/
struct s_dll
{
	t_m_dll mm;
	t_d_dll dd;
	t_u_dll uu;
	t_c_dll cc;
	size_t length;
	t_dll_l where;
	t_dll_l tail;
	t_dll_l head;
};

/*
**    prototype method
*/
t_dll_l add_end_dll(t_dll dll, void *content, size_t size);
void delete_link_dll(t_dll dll, size_t index, t_dll_l link);
t_dll_l add_begin_dll(t_dll dll, void *content, size_t size);
t_dll_l add_at_index_dll(t_dll dll, void *content, size_t size, size_t index);
t_dll_l drop_link_dll(t_dll dll, size_t index, t_dll_l link_given);

/*
**    prototype circular method ================================================
*/

t_dll_l drop_link_circular(t_dll dll);

/*
**    si l != null le link est add sinon il faut content et size
*/
t_dll_l
add_begin_circular_dll(t_dll dll, void *content, size_t size, t_dll_l l);
t_dll_l circular_push_dll(t_dll dll, t_dll_l link);
void circular_destroy_ddl(t_dll *dll);
t_dll_l circular_find_by_nb(t_dll dll, int nb, int (*cmp)(t_dll_l, int));

/*
**    prototype debug
*/
void print_by_head_ddl(t_dll dll, char separateur);
void print_by_tail_ddl(t_dll dll, char separateur);
void print_ddl(t_dll dll, char separateur);
void print_circular_nb(t_dll dll, char separateur);

/*
**    utils
*/
int check_data_ddl(void *content, size_t content_size);

/*
**    prototype constructor
*/
t_dll new_double_linked_list();

#endif
