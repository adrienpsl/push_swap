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

#include "../../../includes/libft.h"

void	ft_buff_addchar_str(char for_print, t_buff_str *buff)
{
	char s[2];

	s[1] = 0;
	s[0] = for_print;
	if (ft_fill_buff_str(s, buff) == 0)
	{
		ft_print_buff_str(buff);
		ft_fill_buff_str(&for_print, buff);
	}
}


