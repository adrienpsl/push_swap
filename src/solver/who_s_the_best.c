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

int test_the_nb(t_dll_l tested_link, size_t lenght, int match)
{
	size_t index;
	int nb_tested;
	int nb_current;
	int difference;

	index = 0;
	nb_tested = dll_l_get_int(tested_link);
	tested_link = tested_link->next;

	while (index < lenght)
	{
		nb_current = dll_l_get_int(tested_link);
		difference = nb_tested - nb_current;
		if (nb_tested == (int) lenght)
		{
			nb_tested = nb_current;
			continue;
		}
//		if (nb_current > nb_tested)
//		{
//			nb_tested = nb_current;
//			match += 1;
//		}
		 else if (difference < 2 && difference >= 0)
			match += 1;
		index += 1;
		tested_link = tested_link->next;
	}
	return (match);
}

int whose_the_best(t_dll_c list_a)
{
	size_t index;
	t_dll_l current_link;
	int current_nb;
	int score_current_nb;
	int new_score;

	index = 0;
	current_link = list_a->top;
	current_nb = dll_l_get_int(current_link);
	score_current_nb = test_the_nb(current_link, list_a->length - 1, 0);
	while (index < list_a->length)
	{
		current_link = current_link->next;
		new_score = test_the_nb(current_link, list_a->length - 1, 0);
		if (new_score > score_current_nb)
		{
			score_current_nb = new_score;
			current_nb = dll_l_get_int(current_link);
		}
		index++;
	}
	ft_printf("%d %d\n", current_nb, score_current_nb);
	return (1);
}