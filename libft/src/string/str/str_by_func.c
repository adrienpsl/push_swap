/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_by_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:43 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_by_func(char *s, int (*f)(int))
{
	if (!s)
		return (0);
	while (*s)
	{
		if (f(*s))
			return (1);
		s++;
	}
	return (0);
}