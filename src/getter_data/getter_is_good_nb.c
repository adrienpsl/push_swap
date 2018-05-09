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

#include "../../header/all_includes.h"

static long		is_a_number(int nb, char *nb_str)
{
	if (nb == 0 && ft_strchr(nb_str, '0') == FALSE)
		return (FALSE);
	return (TRUE);
}

static int		is_an_int(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		exit_wrong_nb();
	return ((int) nb);
}

static int		cmp_exist(int nb1, int nb2)
{
	return (nb1 == nb2);
}

static void		is_single(t_dll_c c_list, int nb)
{
	if (dll_l_iter_int(c_list, nb, &cmp_exist) != FALSE)
		exit_wrong_nb();
}

int				is_valide_number(char *nb_str, t_dll_c c_liste)
{
	long nb;

	nb = ft_atoi(nb_str);
	if (is_a_number(nb, nb_str) == FALSE)
		exit_wrong_nb();
	nb = is_an_int(nb);
	is_single(c_liste, nb);
	return ((int) nb);
}
