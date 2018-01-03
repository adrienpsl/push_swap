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

void do_op(char *op)
{
//	if check_char_into_str("")
}

int get_op(int ac, char **av, int i)
{
	while (i < ac)
	{
		printf("%s \n", av[i]);
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
	get_op(ac,av,i);
	pll(&pw);
	return (0);
}


