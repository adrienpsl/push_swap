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

static int zero(int n, char *str)
{
	if(n == 0)
	{
		str[0] = 0 + '0';
		str[1]= '\0';
		return (TRUE);
	}
	return (FALSE);
}


void ft_putnbr_str(int n, char *str)
{
	int n_tmp;
	int size;

	if (zero(n, str) == TRUE)
		return;
	n_tmp = n;
	size = 0;
	while (n_tmp)
	{
		size++;
		n_tmp /= 10;
	}
	str[size] = '\0';
	size--;
	while (n)
	{
		str[size] = (n % 10 ) + '0';
		n /= 10;
		size--;
	}
}