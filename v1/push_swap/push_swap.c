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

#include "../push_swap.h"

void get_mediane(t_pw *pw)
{
	pw->mediane = pw->tab[pw->tab_max / 2];
}

void set_tab(t_pw *pw)
{
	pw->mediane = pw->lst_a->length / 2;
}

/*
**	1 set la list b
 *	2 trie le tab
 *	3 met les index dans la double list chainer
 *	4 get le pivot du premier passage
 *	5 appelle solver une fois
 *
*/

void push_swap(t_pw *pw)
{
	int *tab;

	make_circle(pw->lst_a);
	if ((pw->lst_b = ft_new_dlst()) == FAIL)
		ft_exit_lack_memory();

	tab = get_tab(pw);
	ft_quick_sort(tab, 0, pw->lst_a->length - 1, pw->lst_a->length - 1);

	// j'imprime le tab
	p_tab(tab, pw->lst_a->length);
	put_index_lst(pw->lst_a, tab);
	pw->tab = tab;
	get_mediane(pw);

	ft_solver(pw);
	pw->mediane = pw->tab_max / 2 + pw->tab_max /4;
	pw->mediane = tab[pw->mediane];
	ft_solver(pw);

	pw->mediane = pw->tab_max + 1;
	ft_solver(pw);
}

/*
**    mem 0 pw
**    set lst_a
**    lauch push_swap
*/

int main(int ac, char **av)
{
	t_pw pw;

	if (ac == NO_ARGV)
		exit(42);
	ft_memset(&pw, 0, sizeof(t_pw));
	pw.lst_a = ft_pw_reader(ac, av);
	push_swap(&pw);

	return (0);
}
