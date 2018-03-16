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

#include "../../../../header/all_includes.h"

static void is_empty_or_one(t_stack stack)
{
	do_instruct("pb", stack);
}

static int nb_is_more_lim(int nb, t_stack stack)
{
	return (nb <= stack->min_lim || nb > stack->max_lim);
}

void set_min_max(t_stack stack, int nb)
{
	if (stack->max_lim < nb)
		stack->max_lim = nb;
	if (stack->min_lim > nb)
		stack->min_lim = nb;
}

//static void search_and_do_instruct(t_stack stack)
//{
//	int resultat_best_way;
//
//	resultat_best_way = is_biggest_lowest(stack, SEARCH);
//	is_biggest_lowest(stack, resultat_best_way);
//	do_instruct("pb", stack);
//}

void push_in_b(t_stack stack)
{
	t_dll_c pile_b;
	int nb;

	nb = get_int_ddl_l(stack->pile_a->top);
	pile_b = stack->pile_b;
	if (pile_b->length <= 1)
		is_empty_or_one(stack);
	else if (nb_is_more_lim(nb, stack) == TRUE)
	{

		nb_is_limit(stack);

		// je trouve le nb
			// lim ?
			// plus petit ?
			// plus grand ?
		// je regarde le nombre de mouvement min pour le put
		// je les fais


		// je cherche direct le plus grand avec une function find nb,
		// qui me retourn le nb de rb ou rrb a faire pour put le nb
		//		resultat_best_way = is_biggest_lowest(stack, SEARCH);
		//		is_biggest_lowest(stack, resultat_best_way);
		//		do_instruct("pb", stack);
	}
	else
	{
//		resultat_best_way = is_normal(stack, resultat_best_way);
//		is_normal(stack, resultat_best_way);
		do_instruct("pb", stack);
	}
	set_min_max(stack, nb);
}
