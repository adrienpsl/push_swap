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



void devant_derriere(int nb, int max, t_stack stack)
{
	if (nb >= max)
		do_instruct(m_inst('p', stack, FALSE), stack);

	// quand il y a juste un nb au debut je fais un mouv pour rien
	else
	{
		do_instruct(m_inst('p', stack, FALSE), stack);
		do_instruct(m_inst('r', stack, FORCE_OP), stack);
	}
}

void get_median_push(t_dll_c pile, t_browse *browse)
{
	size_t nb_link;
	t_dll_l link;
	t_dll_l link_copie;
	t_dll_c pile_copie;
	size_t lim;

	pile_copie = new_dll_c();
	link = pile->top;
	lim = browse->lim;
	while (lim > 0)
	{
		nb_link = dll_l_get_int(link);
		if (nb_link <= browse->med)
		{
			link_copie = new_dll_l(link->content, sizeof(int));
			dll_c_push_link(link_copie, pile_copie);
		}
		lim -= 1;
		link = link->next;
	}
	if (pile_copie->length <= 5)
		browse->option = 0;
	//	dll_c_print_lst(pile_copie);
	browse->median_push = get_med(pile_copie, pile_copie->length);
	destroy_dll_c(&pile_copie);
}

static void browse_push(t_browse *browse, t_stack stack, int top_pile, int med)
{
	t_dll_c pile;

	pile = browse->pile == PILE_A ? stack->pile_a : stack->pile_b;
	set_quick(browse->quick_count, pile->top);
	if (browse->option == DEVANT_DERRIERE)
		devant_derriere(top_pile, med, stack);
	else
		do_instruct(m_inst('p', stack, FALSE), stack);
}

void browse_pile(t_stack stack, t_browse *browse)
{
	size_t top_pile;
	t_dll_c pile;
	size_t lim;

	lim = browse->lim;
	pile = browse->pile == PILE_A ? stack->pile_a : stack->pile_b;
	get_median_push(pile, browse);
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if (top_pile < browse->med)
			browse_push(browse, stack, top_pile, browse->median_push);
		else
			do_instruct(m_inst('r', stack, FALSE), stack);
		lim -= 1;
		print_stack(stack);
	}
	browse->quick_count += 1;
}

//int med_devant_derriere(t_dll_c pile, int max, size_t lim)
//{
//	int nb_link;
//	t_dll_l link;
//	t_dll_l link_copie;
//	t_dll_c pile_copie;
//	int median;
//
//	pile_copie = new_dll_c();
//	link = pile->top;
//	while (lim > 0)
//	{
//		nb_link = dll_l_get_int(link);
//		if (nb_link <= max)
//		{
//			link_copie = new_dll_l(link->content, sizeof(int));
//			dll_c_push_link(link_copie, pile_copie);
//		}
//		lim -= 1;
//		link = link->next;
//	}
//
//	median = get_med(pile_copie, pile_copie->length);
//	destroy_dll_c(&pile_copie);
//	return (median);
//}
//
//void browse_pile_a(t_stack stack, int max, size_t lim, int option)
//{
//	int top_pile;
//	t_dll_c pile;
//	int med_devant_derrier;
//	int static quick_count = 0;
//
//	pile = stack->pile_a;
//	med_devant_derrier = med_devant_derriere(pile, max, lim);
//	while (lim > 0)
//	{
//		top_pile = dll_l_get_int(pile->top);
//		if (top_pile < max)
//		{
//			if (option == DEVANT_DERRIERE)
//			{
//				set_quick(quick_count, stack->pile_a->top);
//				devant_derriere(top_pile, med_devant_derrier, stack);
//			}
//			else
//				do_instruct("pb", stack);
//		}
//		else
//			do_instruct("ra", stack);
//		lim -= 1;
//	}
//	quick_count += 1;
//}
//
////void devant_derriere(int nb, int max, t_stack stack)
////{
////	if (nb >= max)
////		do_instruct("pb", stack);
////	else
////	{
////		do_instruct("pb", stack);
////		do_instruct("rb", stack);
////	}
////}
//
//
//void browse_pile_b(t_stack stack, int max, size_t lim, int option)
//{
//	int top_pile;
//	t_dll_c pile;
//	int med_devant_derrier;
//	int static quick_count = 0;
//
//	pile = stack->pile_b;
//	med_devant_derrier = med_devant_derriere(pile, max, lim);
//	while (lim > 0)
//	{
//		top_pile = dll_l_get_int(pile->top);
//		if (top_pile >= max)
//		{
//			if (option == DEVANT_DERRIERE)
//			{
//				set_quick(quick_count, stack->pile_b->top);
//				devant_derriere(top_pile, med_devant_derrier, stack);
//			}
//			else
//				do_instruct("pa", stack);
//		}
//		else
//			do_instruct("rb", stack);
//		lim -= 1;
//	}
//	quick_count += 1;
//}