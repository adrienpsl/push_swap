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

void	sa(t_stack stack)
{
	t_dll_c			pile_a;
	struct s_data	a;
	struct s_data	b;

	pile_a = stack->pile_a;
	if (pile_a->length > 1)
	{
		ft_memcpy(&a, pile_a->top->content, sizeof(struct s_data));
		ft_memcpy(&b, pile_a->top->next->content, sizeof(struct s_data));
		ft_memcpy(pile_a->top->content, &b, sizeof(struct s_data));
		ft_memcpy(pile_a->top->next->content, &a, sizeof(struct s_data));
	}
}

void	sb(t_stack stack)
{
	t_dll_c			pile_b;
	struct s_data	a;
	struct s_data	b;

	pile_b = stack->pile_b;
	if (pile_b->length > 1)
	{
		ft_memcpy(&a, pile_b->top->content, sizeof(struct s_data));
		ft_memcpy(&b, pile_b->top->next->content, sizeof(struct s_data));
		ft_memcpy(pile_b->top->content, &b, sizeof(struct s_data));
		ft_memcpy(pile_b->top->next->content, &a, sizeof(struct s_data));
	}
}

void	ss(t_stack stack)
{
	sa(stack);
	sb(stack);
}
