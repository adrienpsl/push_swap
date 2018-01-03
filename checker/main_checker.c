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

void ft_error_ck(void)
{
	ft_putstr("KO\n");
	exit(42);
}

void checker()
{
}

void do_op(char *op,t_pw *pw)
{
	if (ft_strstr("sa", op))
		ft_sa(pw);
	else if (ft_strstr("sb", op))
		ft_sb(pw);
	else if (ft_strstr("ss", op))
		ft_ss(pw);
	else if (ft_strstr("pa", op))
		ft_pa(pw);
	else if (ft_strstr("pb", op))
		ft_pb(pw);
	else if (ft_strstr("ra", op))
		ft_ra(pw);
	else if (ft_strstr("rb", op))
		ft_rb(pw);
	else if (ft_strstr("rr", op))
		ft_rr(pw);
	else if (ft_strstr("rra", op))
		ft_rra(pw);
	else if (ft_strstr("rrb", op))
		ft_rrb(pw);
	else if (ft_strstr("rrr", op))
		ft_rrr(pw);
	else
		ft_error_ck();
}

int get_op(int ac, char **av, int i, t_pw *pw)
{
	while (i < ac)
	{
		do_op(av[i], pw);
		i++;
	}
	return (DONE);
}

int main(int ac, char **av)
{
	t_pw pw;
	int i;

	i = 0;
	if (ac == NO_ARGV)
		exit(42);
	ft_memset(&pw, 0, sizeof(t_pw));
	ft_checker_reader(&pw, ac, av, &i);
	get_op(ac, av, i, &pw);
	pll(&pw);
	return (0);
}


