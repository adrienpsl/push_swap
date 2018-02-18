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

#include "../../checker.h"

static long is_a_number(int nb, char *nb_str)
{
	if (nb == 0 && ft_strchr(nb_str, '0') == FALSE)
		return (FALSE);
	return (TRUE);
}

static int is_an_int(long nb)
{

	if (nb > INT_MAX || nb < INT_MIN)
		exit_wrong_nb();
	return ((int) nb);
}

static int cmp_exist(t_dll_l link, int nb)
{
	if (link->mm.get_content_int(link) == nb)
		return (TRUE);
	return (FALSE);
}

static void is_single(t_dll dll, int nb)
{
	t_dll_l link_exist;
	link_exist = dll->cc.circular_find_by_nb(dll, nb, &cmp_exist);
	if (link_exist != NULL)
		exit_wrong_nb();
}

int is_valide_number(t_getter getter, char *nb_str)
{
	long nb;

	nb = ft_atoi(nb_str);
	if (is_a_number(nb, nb_str) == FALSE)
		exit_wrong_nb();
	nb = is_an_int(nb);
	is_single(getter->pile_a, nb);
	return ((int) nb);
}


/*
int main()
{
 	printf("%ld \n",is_a_number("444"));
 	printf("%ld \n",is_a_number("45464646465464"));
 	printf("%ld \n",is_a_number("-874448"));
 	printf("%ld \n",is_a_number("0"));
 	printf("%ld \n",is_a_number("dd"));

	printf("%d \n",is_an_int("444"));
	printf("%d \n",is_an_int("45464646465464"));
	printf("%d \n",is_an_int("-874448"));
	printf("%d \n",is_an_int("0"));
	printf("%d \n",is_an_int("dd"));
    return (0);
}*/
