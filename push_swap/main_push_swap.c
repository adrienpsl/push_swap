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

#include "push_swap.h"

void		p_tab(int tab[], int limit)
{
	int i;

	i = 0;
	printf("[[ ");
	while (i < limit)
	{
		printf("%d, ", tab[i]);
		++i;
	}
	printf("]]\n");
}

void push_swap(t_pw *pw)
{
	int *tab;

	tab = get_tab(pw);

	ft_quick_sort(tab,0,pw->lst->length - 1,pw->lst->length - 1);
	p_tab(tab,pw->lst->length);
}

int main(int ac, char **av)
{
	t_pw pw;

	if (ac == NO_ARGV)
		exit(42);
	pw.lst = ft_main_reader(ac, av);
	push_swap(&pw);

	return (0);
}
