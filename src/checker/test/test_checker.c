///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_atoi.c                                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
///*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../header_checker.h"
//
//// check all instruc :
//	 // 33 55 74 99 2 sa sb ss pa pb ra rb rr rra rrb d
//
//t_pile pile;
//
//t_dll pile_a;
//
//t_dll pile_b;
//
//void static init()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//
//	pile_a = new_double_linked_list();
//	pile_a->cc.circular_add_begin(pile_a, &a, sizeof(int), NULL);
//	pile_a->cc.circular_add_begin(pile_a, &b, sizeof(int), NULL);
//	pile_a->cc.circular_add_begin(pile_a, &c, sizeof(int), NULL);
//	pile_a->cc.circular_add_begin(pile_a, &d, sizeof(int), NULL);
//	pile = new_pile(pile_a);
//	pile_b = pile->pile_b;
//}
//
//void static destroy()
//{
//	pile->mm.destroy(&pile);
//}
//
//static void test__1_() // verif is ordered
//{
//	init();
//
//	char *str="test 1 \n test de verif is ordered";
//	pile_a->cc.print_circular_nb(pile_a,' ');
//	is_ordered(pile_a);
//	destroy();
//}
//
//
//
//static void all_test()
//{
//	test__1_();
//}
//
////int main()
////{
////	all_test();
////	return (0);
////}