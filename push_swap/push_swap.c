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

static int call = 0;

void pll(t_pw *pw)
{
	call++;
	printf("=====  call %d ============================= \n", call);
	if (pw->lst_a->length)
	{
		printf("list a :  ");
		pl(pw->lst_a);
	}
	if (pw->lst_b->length)
	{
		printf("list b :  ");
		pl(pw->lst_b);
	}
}

void pp(void (*fun)(t_pw *pw), t_pw *p)
{
	fun(p);
	pll(p);
}
void push_swap(t_pw *pw)
{
	int *tab;

	tab = get_tab(pw);
	//	ft_quick_sort(tab,0,pw->lst_a->length - 1,pw->lst_a->length - 1);
	//	p_tab(tab,pw->lst_a->length);
}

int main(int ac, char **av)
{
	t_pw pw;

	if (ac == NO_ARGV)
		exit(42);
	ft_memset(&pw, 0, sizeof(t_pw));
	pw.lst_a = ft_pw_reader(ac, av);
	if ((pw.lst_b = ft_new_dlst()) == FAIL)
		ft_exit_lack_memory();

	//	push_swap(&pw);
	make_circle(pw.lst_a);
	pp(&ft_pb, &pw);
	pp(&ft_pb, &pw);

//	pp(&ft_sa, &pw);

	pp(&ft_pb, &pw);
	pp(&ft_pb, &pw);
	pp(&ft_pb, &pw);

//		pp(& ft_pb, &pw);
	//	pp(& ft_pb, &pw);
	//
	//	pp(& ft_pa, &pw);



	return (0);
}
