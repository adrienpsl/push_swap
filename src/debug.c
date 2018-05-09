# include "../header/all_includes.h"

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
	ft_printf("\n\n------------------------------------------- \n");
	ft_printf("A :");
	dll_c_print_lst(stack->pile_a);
	ft_printf("   ");
	print_quick(stack->pile_a);
	ft_printf(" \n");
	ft_printf("B :");
	dll_c_print_lst(stack->pile_b);
	ft_printf("   ");
	print_quick(stack->pile_b);
	printf(" \n");;
	ft_printf("%d \n", stack->count);
};