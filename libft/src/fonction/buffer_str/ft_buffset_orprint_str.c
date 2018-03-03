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

/*
**	manage buff for this project
*/

void	buff_set_or_print(char *for_print, t_buff_str *buff)
{
	if (ft_fill_buff_str(for_print, buff) == 0)
	{
		ft_print_buff_str(buff);
		ft_fill_buff_str(for_print, buff);
	}
}
