/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:06 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:44 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**  externals lib
*/
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/*
**	for more clarter
*/
# include "src/libft_define.h"

/*
**	buffer_str
*/
# include "src/libft_buffer_str.h"

/*
**  memory function
*/
# include "src/libft_memory_function.h"


/*
**  text function
*/
# include "src/libft_str_function.h"

/*
**  text nb
*/
# include "src/libft_nb_function.h"

/*
**  function lst
*/
# include "src/libft_lst_function.h"

/*
**  function d_lst
*/
# include "src/libft_d_lst_function.h"

/*
**    debug
*/
#include "src/libft_debug.h"


/*
**	double linked list link
*/
# include "src/dll_l_header.h"

/*
**	double linked circular list
*/
# include "src/dll_c_header.h"

/*
**    object argv
*/
# include "src/argv_header.h"

/*
**	quick sort
*/
void ft_quick_sort(int tab[], int start, int end, int last);
void		p_tab(int tab[], int limit);

#endif
