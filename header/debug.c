# include "all_includes.h"

void		p_tab(int tab[], int limit)
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

void print_stack(t_stack stack)
{
	dll_c_print_lst(stack->pile_a);
	dll_c_print_lst(stack->pile_b);
};