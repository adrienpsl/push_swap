///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   main.c                                             :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/10/19 10:48:06 by adpusel           #+#    #+#             */
///*   Updated: 2017/10/19 10:48:06 by adpusel          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "./includes/libft.h"
//
//int *get_tab(t_dlist *pw)
//{
//	int *tab;
//	t_dlink *link;
//	long i;
//
//	link = pw->head;
//	i = 0;
//	if ((tab = (int *) malloc(sizeof(int) * (pw->length + 1))) == FAIL)
//		ft_exit_lack_memory();
//	tab[pw->length] = 0;
//	while (link)
//	{
//		tab[i] = *(int *) link->content;
//		link = link->next;
//		i++;
//	}
//	return (tab);
//}
//
//int main()
//{
//	t_dlist *o;
//
//	o = ft_new_dlst();
//	int a = 8;
//	int b = 4;
//	int c = -88;
//	int d = 744554;
//
//	ft_dlst_add_end(o, &a, 4);
//	ft_dlst_add_end(o, &b, 4);
//	ft_dlst_add_end(o, &c, 4);
//	ft_dlst_add_end(o, &d, 4);
//	ft_dlst_insert_atindex(o,100,&d,4);
//
//	printf("%d \n", *(int*)o->head->next->content);
//	ft_dlst_clear_all(&o);
//
//
//	//	printf("%d \n", *(int*)l->content);
////	int *tab = get_tab(o);
////	p_tab(tab,o->length);
////	ft_quick_sort(tab, 0, o->length - 1, o->length - 1);
////	p_tab(tab,o->length);
//	return 0;
//}
