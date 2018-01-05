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