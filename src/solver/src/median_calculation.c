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

// ca ne prends pas en compte le dernier nb, ajouter +1 si nb impaire
void get_median(t_stack stack, int occurs)
{

	if (stack->median_junp == 0)
		stack->median_junp = stack->pile_a->length / occurs;

	stack->mediane_down = stack->mediane_up;

	stack->mediane_up += stack->median_junp;

	stack->min_lim = stack->mediane_up;

	stack->max_lim = stack->mediane_down;


}