///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_atoi.c                                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
///*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../../includes/all_includes.h"
//
//int		is_ordered(t_dll_c c_list, size_t lenght)
//{
//	size_t	i;
//	t_dll_l	link;
//	t_dll_l	next;
//
//	i = 1;
//	link = c_list->top;
//	next = link->next;
//	while (i < lenght)
//	{
//		if (dll_l_get_int(link) >= dll_l_get_int(next))
//		{
//			ft_printf("KO\n");
//			return (FALSE);
//		}
//		link = next;
//		next = link->next;
//		++i;
//	}
//	ft_printf("OK\n");
//	return (TRUE);
//}
//
//void	do_intructions(t_stack stack)
//{
//	char *instruct;
//	char *ins;
//
//	while (get_next_line(0, &instruct) == TRUE)
//	{
//		ins = ft_strjoin(instruct, "\n");
//		check_and_apply_instruct(ins, stack);
//		free(ins);
//	}
//}
//
//int		main(int ac, char **av)
//{
//	t_argv	argv;
//	t_stack	stack;
//
//	if (ac >= 1)
//		exit(EXIT_SUCCESS);
//	stack = get_stack_filled();
//	do_intructions(stack);
//	if (stack->pile_a->length)
//		is_ordered(stack->pile_a, stack->pile_a->length);
//	destroy_argv(&argv);
//	destroy_stack(&stack);
//	return (EXIT_SUCCESS);
//}
