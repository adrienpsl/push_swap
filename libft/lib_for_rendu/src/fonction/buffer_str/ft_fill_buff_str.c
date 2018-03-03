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
**	fill the buff with str, update buff and return 1
**	if str didn't fit, return 0
*/

int		ft_fill_buff_str(char *str, t_buff_str *buff)
{
	size_t size_str;

	size_str = ft_strlen(str);
	if (size_str <= buff->remain_space - 1)
	{
		ft_strcat(buff->data, str);
		buff->remain_space = buff->remain_space - size_str;
		return (1);
	}
	else
		return (0);
}
