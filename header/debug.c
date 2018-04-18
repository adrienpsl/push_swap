# include "all_includes.h"

void p_tab(int tab[], int limit)
{
	int i;

	i = 0;
	ft_putstr("[[ ");
	while (i < limit)
	{
		printf("%d, ", tab[i]);
		++i;
	}
	printf("]]\n");
}

void print_quick(t_dll_c lst)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;
	while (i != -1)
	{
		ft_printf("%2d ", get_quick(link));
		i--;
		if (i == 0)
			ft_printf(" -- ");
		link = link->next;
	}
	ft_printf(" \n");
}

void print_stack(t_stack stack)
{
	(void) stack;


	//print les instruction
	ft_printf(" \n");

	static t_sll_l last_prev_instruct = NULL;
	//
	if (last_prev_instruct != NULL)
		sll_print_str_link(last_prev_instruct->next);
	else
		sll_print_str(stack->instruction);
	last_prev_instruct = stack->instruction->tail;

	ft_printf("\n------------------------------------------- \n");

	// printe les lists
	dll_c_print_lst(stack->pile_a);
	print_quick(stack->pile_a);
	if (stack->pile_a->length == 0)
		printf(" \n");;
	ft_printf(" \n");

	dll_c_print_lst(stack->pile_b);
	print_quick(stack->pile_b);
	if (stack->pile_b->length == 0)
		printf(" \n");;
};