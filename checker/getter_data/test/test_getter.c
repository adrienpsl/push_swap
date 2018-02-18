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

#include "../../checker.h"

static void
test__1_() // test si le getter link bien avec le getter pour les options
{
	//	char *str="test 1 \n test de test si le getter link bien avec le get_op pour les options";

	char **av = ft_strsplit("1 2 4", ' ');

	t_getter getter;
	t_dll pile_a;
	int a = 42;
	int b = -42;
	int c = 4242;
	t_argv argv;

	argv = new_argv(4, NULL);
	getter = new_getter(argv);

	pile_a = getter->pile_a;

	pile_a->cc.circular_add_begin(pile_a, &a, sizeof(int), NULL);
	pile_a->cc.circular_add_begin(pile_a, &b, sizeof(int), NULL);
	pile_a->cc.circular_add_begin(pile_a, &c, sizeof(int), NULL);

	getter->mm.is_valide_number(getter, "-2147483648");
	getter->mm.is_valide_number(getter, "2147483647");

	getter->mm.destroy(&getter);
	pile_a->cc.circular_destroy(&pile_a);
	argv->mm.destroy(&argv);
	ft_free_split(&av);
}

static void test__2_() // test add nb man
{
	char *str = "test 2 \n test de test add nb man";
	(void) str;
	char **av = ft_strsplit("42 1 2 4", ' ');
	t_getter getter;
	t_dll pile_a;

	t_argv argv;
	argv = new_argv(4, av);

	getter = new_getter(argv);
	getter->mm.get_lst_a(getter);

	pile_a = getter->pile_a;
	printf("%d \n", pile_a->where->mm.get_content_int(pile_a->where));
	printf("%d \n", pile_a->where->mm.get_content_int(pile_a->where->next));
	printf("%d \n",
		   pile_a->where->mm.get_content_int(pile_a->where->next->next));
	printf("%d \n",
		   pile_a->where->mm.get_content_int(pile_a->where->next->next->next));

	pile_a->cc.circular_destroy(&pile_a);
	getter->mm.destroy(&getter);
	argv->mm.destroy(&argv);
	ft_free_split(&av);
}

static void test__3_() // test add nb man
{
	char *str = "test 3 \n test avec une seule chaine comme av  ";
	(void) str;
	char **av;
	av = ft_malloc_protect(sizeof(char *) * 3);
	av[0] = ft_strdup("programme");
	av[1] = ft_strdup("1 4 5 6 8888  7  ");
	av[2] = 0;
	t_getter getter;
	t_dll pile_a;

	t_argv argv;
	argv = new_argv(2, av);

	getter = new_getter(argv);
	getter->mm.get_lst_a(getter);

	pile_a = getter->pile_a;
//	printf("%d \n", pile_a->where->mm.get_content_int(pile_a->where));
//	printf("%d \n", pile_a->where->mm.get_content_int(pile_a->where->next));
//	printf("%d \n",
//		   pile_a->where->mm.get_content_int(pile_a->where->next->next));
//	printf("%d \n",
//		   pile_a->where->mm.get_content_int(pile_a->where->next->next->next));

	pile_a->cc.circular_destroy(&pile_a);
	getter->mm.destroy(&getter);
	argv->mm.destroy(&argv);
	ft_free_split(&av);
}

static void test__4_(int ac,
 char **av) // avec les argument qui viennent directemetn du main
{
	char *str = "test 4 \n test de avec les argument qui viennent directemetn du main";
	(void) str;
	t_getter getter;
	t_dll pile_a;

	t_argv argv;
	argv = new_argv(ac, av);

	getter = new_getter(argv);
	getter->mm.get_lst_a(getter);

	pile_a = getter->pile_a;
//	printf("%d \n", pile_a->where->mm.get_content_int(pile_a->where));
//	printf("%d \n", pile_a->where->mm.get_content_int(pile_a->where->next));
//	printf("%d \n",
//		   pile_a->where->mm.get_content_int(pile_a->where->next->next));
//	printf("%d \n",
//		   pile_a->where->mm.get_content_int(pile_a->where->next->next->next));
	getter->pile_a->cc.print_circular_nb(pile_a, ' ');

	printf("%zu  %d\n", pile_a->length, ac);
	printf("%s \n",av[argv->count]);

	pile_a->cc.circular_destroy(&pile_a);
	getter->mm.destroy(&getter);
	argv->mm.destroy(&argv);
}

void test_getter(int ac, char **av)
{
//	test__1_();
//	test__2_();
//	test__3_();
	test__4_(ac, av);
}

int main(int ac, char **av)
{
	test_getter(ac, av);
	return (0);
}