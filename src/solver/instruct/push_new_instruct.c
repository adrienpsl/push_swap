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

#include "../../../includes/all_includes.h"

int		rr_style(char *instr, t_stack stack)
{
	char *last;

	last = stack->last_instruct;
	if ((ft_strcmp(instr, "rrb") == FALSE &&
			ft_strcmp(last, "rra") == FALSE)
		||
		(ft_strcmp(instr, "rra") == FALSE &&
			ft_strcmp(last, "rrb") == FALSE))
	{
		push_instruc_list("rrr", stack);
		return (TRUE);
	}
	return (FALSE);
}

int		r_style(char *instr, t_stack stack)
{
	char *last;

	last = stack->last_instruct;
	if ((ft_strcmp(instr, "rb") == FALSE &&
			ft_strcmp(last, "ra") == FALSE)
		||
		(ft_strcmp(instr, "ra") == FALSE &&
			ft_strcmp(last, "rb") == FALSE))
	{
		push_instruc_list("rr", stack);
		return (TRUE);
	}
	return (FALSE);
}

void	do_instruct(char *instruc, t_stack stack)
{
	check_and_apply_instruct(instruc, stack);
	if (*stack->last_instruct)
	{
		if (r_style(instruc, stack) || rr_style(instruc, stack))
		{
			ft_memset(stack->last_instruct, 0, sizeof(char) * 4);
			stack->count++;
			return ;
		}
		else
			push_instruc_list(stack->last_instruct, stack);
		stack->count++;
		ft_memset(stack->last_instruct, 0, sizeof(char) * 4);
		ft_strcpy(stack->last_instruct, instruc);
	}
	else
		ft_strcpy(stack->last_instruct, instruc);
}
