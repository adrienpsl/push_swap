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

/*
**    last_prev_instruc est le link de la derniere instruction pour pouvoir
**    print uniquement la fin
*/

void print_stack(t_stack stack)
{
	(void) stack;

//	static t_sll_l last_prev_instruct = NULL;

	//print les instruction
//	printf("instrc : ");
//	if (last_prev_instruct != NULL)
//		sll_print_str_link(last_prev_instruct->next);
//	else
//		sll_print_str(stack->instruction);
//	last_prev_instruct = stack->instruction->tail;

	printf("\n===================================== \n");
	// printe les lists
	dll_c_print_lst(stack->pile_a);
	if (stack->pile_a->length == 0)
		printf(" \n");;

	dll_c_print_lst(stack->pile_b);
	if (stack->pile_b->length == 0)
		printf(" \n");;


	//les mediane



	printf(" \n");
};