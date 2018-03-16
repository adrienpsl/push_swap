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

#include "../../../header/all_includes.h"

void get_median(t_stack stack)
{
	static int count = 0;

	stack->mediane_down = stack->mediane_up;

	stack->mediane_up = (stack->pile_a->length / 2) + stack->mediane_up;

	if (stack->pile_a->length % 2)
		stack->mediane_up += 1;
	stack->min_lim = stack->mediane_up;



	// faire un calcule pour les nombre impaires
	// j'ai un de trop voir comment equilibrer
	// min deviens le premier nb de la nouvelle sequence
	// une fonction qui update medium plus et medium minus
	// c'est la que ca bloque pour le moment.
//	if (count)
//	{
		stack->max_lim = stack->mediane_down;
//	}
	count += 1;
}