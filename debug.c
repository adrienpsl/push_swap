#include "push_swap.h"


void phead(t_dlist *l)
{
	size_t i;
	t_dlink *tmp;

	i = 0;
	tmp = l->head;
	printf("[[ ");
	while(i < l->length)
	{
		printf("%d, ", *(int *)tmp->content);
		tmp = tmp->prev;
		i++;
	}
	printf("]] \n");
}

static int call = 0;

void pll(t_pw *pw)
{
	call++;
	printf("=====  call %d ============================= \n", call);
	if (pw->lst_a->length)
	{
		printf("list a :  ");
		pl(pw->lst_a);
	}
	if (pw->lst_b->length)
	{
		printf("list b :  ");
		pl(pw->lst_b);
	}
}

void pp(void (*fun)(t_pw *pw), t_pw *p)
{
	fun(p);
	pll(p);
}