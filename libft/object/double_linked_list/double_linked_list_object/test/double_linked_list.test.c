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

#include "../../double_linked_list.h"

static void test__1_()
{
	char *str = "test 1 \n test de la list et destroy valgrind";

	t_dll list = new_double_linked_list();
	(void) str;
	list->mm.destroy(&list);
}

static void test__2_()
{
	char *str = "test 2 \n test des valeur de l'objet";

	t_dll list = new_double_linked_list();

	if (1 &&
		list->where != NULL ||
		list->head != NULL ||
		list->tail != NULL ||
		list->length != 0)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__3_() // "test 3 \n test add_begin avec des valeurs NULL";
{

	t_dll list = new_double_linked_list();
	list->mm.add_begin(list, "1", 2);
	list->mm.destroy(&list);
}

static void test__4_() // ajout un maillon avec str
{
	char *str = "test 4 \n test de ajout un maillon avec str";
	t_dll list = new_double_linked_list();
	list->mm.add_begin(list, "42", 3);

	if (ft_strcmp(list->head->content, "42") || list->head->content_size != 3)
		printf("%s \n", str);

	if (list->length != 1)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__5_() // test ajout de 2 link head
{
	char *str = "test 5 \n test de test ajout de 2 link head";

	t_dll list = new_double_linked_list();
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "4242", 5);

	if (ft_strcmp(list->head->content, "4242") || list->head->content_size != 5)
		printf("%s \n", str);

	if (ft_strcmp(list->head->next->content, "42") ||
		list->head->next->content_size != 3)
		printf("%s \n", str);

	if (list->length != 2)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__6_() // test ajout de 2 link tail
{
	char *str = "test 6 \n test de test ajout de 2 link tail";

	t_dll list = new_double_linked_list();
	list->mm.add_end(list, "42", 3);
	list->mm.add_end(list, "4242", 5);

	if (ft_strcmp(list->tail->content, "4242") || list->tail->content_size != 5)
		printf("%s \n", str);

	if (ft_strcmp(list->tail->prev->content, "42") ||
		list->tail->prev->content_size != 3)
		printf("%s \n", str);

	if (list->length != 2)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__7_() // add un devant un derriere
{
	char *str = "test 7 \n test de add un devant un derrier";
	t_dll list = new_double_linked_list();
	list->mm.add_end(list, "42", 3);
	list->mm.add_begin(list, "4242", 5);

	if (ft_strcmp(list->head->content, "4242") || list->head->content_size != 5)
		printf("%s \n", str);

	if (ft_strcmp(list->tail->content, "42") ||
		list->tail->content_size != 3)
		printf("%s \n", str);

	if (list->length != 2)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__8_() // add_at_index check index 0 list vide || pleine
{
	char *str = "test 8 \n test de add_at_index check index 0 ";

	t_dll list = new_double_linked_list();
	list->mm.add_at_index(list, "42", 3, 0);

	if (ft_strcmp(list->head->content, "42") || list->head->content_size != 3)
		printf("%s \n", str);

	list->mm.add_at_index(list, "4242", 5, 0);

	if (ft_strcmp(list->head->content, "4242") || list->head->content_size != 5)
		printf("%s \n", str);

	if (ft_strcmp(list->head->next->content, "42") ||
		list->head->next->content_size != 3)
		printf("%s \n", str);

	if (list->length != 2)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__9_() // add_at_index check list index trop grand
{
	char *str = "test 9 \n test de add_at_index check list index trop grand";

	t_dll list = new_double_linked_list();

	list->mm.add_at_index(list, "42", 3, 100);

	if (ft_strcmp(list->head->content, "42") || list->head->content_size != 3)
		printf("%s \n", str);

	list->mm.add_at_index(list, "4242", 5, 100);

	if (ft_strcmp(list->tail->content, "4242") || list->tail->content_size != 5)
		printf("%s \n", str);

	if (ft_strcmp(list->tail->prev->content, "42") ||
		list->tail->prev->content_size != 3)
		printf("%s \n", str);

	if (list->length != 2)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void test__10_() // add_at_index add un derrier un devant
{
	char *str = "test 10 \n test de add un devant un derrier";
	t_dll list = new_double_linked_list();
	list->mm.add_at_index(list, "4242", 5, 10);
	list->mm.add_at_index(list, "42", 3, 0);

	if (ft_strcmp(list->head->content, "42") || list->head->content_size != 3)
		printf("%s \n", str);

	if (ft_strcmp(list->tail->content, "4242") ||
		list->tail->content_size != 5)
		printf("%s \n", str);

	if (list->length != 2)
		printf("%s \n", str);

	list->mm.destroy(&list);
}

static void
test__11_() // test link at good index >>>> a faire en console <<<<<<
{
	char *str = "test 11 \n test de test link at good index";
	(void) str;
	t_dll list = new_double_linked_list();
	list->mm.add_at_index(list, "0", 2, 0);

	list->mm.add_at_index(list, "1", 2, 1);

	list->mm.add_at_index(list, "3", 2, 2);

	list->mm.add_at_index(list, "4", 2, 3);

	list->mm.add_at_index(list, "5", 2, 4);

	list->mm.add_at_index(list, "2", 2, 2);

	list->mm.add_at_index(list, "7", 2, 10);

	list->mm.add_at_index(list, "6", 4, 5);

	printf("doit etre de 0 a 7 ===");
	list->dd.print_by_head(list, ' ');
	printf(" \n");

	list->mm.destroy(&list);
}

static void test__12_() // test de drop link avec 1  et 2 link
{
	char *str = "test 12 \n test de test de drop link";
	(void) str;
	t_dll_l link_test;
	t_dll_l link_test_remaining;
	t_dll_l link_tmp;
	t_dll list = new_double_linked_list();

	list->mm.add_at_index(list, "0", 2, 0);
	link_test = list->mm.drop_link(list, 1, NULL);

	// test one link
	// test le link
	if (1
		&& ft_strcmp(link_test->content, "0")
		|| link_test->content_size != 2
		|| link_test->prev != NULL
		|| link_test->next != NULL
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 0
		|| list->tail != NULL
		|| list->head != NULL
		|| list->where != NULL
	 )
		printf("%s \n", str);

	link_test->mm.destroy(&link_test);

	// test two link
	list->mm.add_at_index(list, "0", 2, 0);
	link_tmp = list->mm.add_at_index(list, "1", 2, 1);
	link_test = list->mm.drop_link(list, 0, NULL);

	// test le link
	if (1
		&& ft_strcmp(link_test->content, "0")
		|| link_test->content_size != 2
		|| link_test->prev != NULL
		|| link_test->next != NULL
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 1
		|| list->tail != link_tmp
		|| list->head != link_tmp
		|| list->where != NULL
	 )
		printf("%s \n", str);

	link_test->mm.destroy(&link_test);
	list->mm.destroy(&list);

	// test two link en partant de la fin
	list = new_double_linked_list();
	link_tmp = list->mm.add_at_index(list, "0", 2, 0);
	list->mm.add_at_index(list, "1", 2, 1);
	link_test = list->mm.drop_link(list, 3, NULL);

	// test le link
	if (1
		&& ft_strcmp(link_test->content, "1")
		|| link_test->content_size != 2
		|| link_test->prev != NULL
		|| link_test->next != NULL
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 1
		|| list->tail != link_tmp
		|| list->head != link_tmp
		|| list->where != NULL
	 )
		printf("%s \n", str);

	link_test->mm.destroy(&link_test);
	list->mm.destroy(&list);

	// test en donnant un link
	list = new_double_linked_list();
	link_test_remaining = list->mm.add_at_index(list, "0", 2, 0);
	link_tmp = list->mm.add_at_index(list, "1", 2, 1);
	link_test = list->mm.drop_link(list, 0, link_tmp);

	// test le link
	if (1
		&& ft_strcmp(link_test->content, "1")
		|| link_test->content_size != 2
		|| link_test->prev != NULL
		|| link_test->next != NULL
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 1
		|| list->tail != link_test_remaining
		|| list->head != link_test_remaining
		|| list->where != NULL
	 )
		printf("%s \n", str);

	link_test->mm.destroy(&link_test);
	list->mm.destroy(&list);


	// test en donnant un link
	list = new_double_linked_list();
	link_tmp = list->mm.add_at_index(list, "0", 2, 0);
	link_test_remaining = list->mm.add_at_index(list, "1", 2, 1);
	link_test = list->mm.drop_link(list, 0, link_tmp);

	// test le link
	if (1
		&& ft_strcmp(link_test->content, "0")
		|| link_test->content_size != 2
		|| link_test->prev != NULL
		|| link_test->next != NULL
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 1
		|| list->tail != link_test_remaining
		|| list->head != link_test_remaining
		|| list->where != NULL
	 )
		printf("%s \n", str);

	link_test->mm.destroy(&link_test);
	list->mm.destroy(&list);
}

static void test__13_() // test avec 3 links
{
	char *str = "test 13 \n test de test avec 3 links";
	(void) str;
	t_dll_l dropped_link;
	t_dll_l link1;
	t_dll_l link2;
	t_dll_l link3;
	t_dll_l link4;
	//	t_dll_l link_tmp;
	t_dll list;

	// trois el ajouter a la list
	list = new_double_linked_list();
	link1 = list->mm.add_at_index(list, "0", 2, 0);
	list->mm.add_at_index(list, "1", 2, 1);
	link2 = list->mm.add_at_index(list, "2", 2, 100);

	//	link_test_remaining = list->mm.add_at_index(list, "2", 2, 100);

	dropped_link = list->mm.drop_link(list, 1, NULL);

	// test le link
	if (1
		&& ft_strcmp(dropped_link->content, "1")
		|| dropped_link->content_size != 2
		|| dropped_link->prev != NULL
		|| dropped_link->next != NULL
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 2
		|| list->tail != link2
		|| list->head != link1
		|| list->where != NULL
	 )
		printf("%s \n", str);

	dropped_link->mm.destroy(&dropped_link);
	list->mm.destroy(&list);

	////////// test avec 4
	list = new_double_linked_list();
	link1 = list->mm.add_at_index(list, "0", 2, 0);
	link2 = list->mm.add_at_index(list, "1", 2, 1);
	link3 = list->mm.add_at_index(list, "2", 2, 100);
	link4 = list->mm.add_at_index(list, "3", 2, 100);

	dropped_link = list->mm.drop_link(list, 2, NULL);

	// test le link
	if (1
		&& ft_strcmp(dropped_link->content, "2")
		|| dropped_link->content_size != 2
		|| dropped_link->prev != NULL
		|| dropped_link->next != NULL
		|| dropped_link != link3
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 3
		|| list->head != link1
		|| list->head->next != link2
		|| list->tail != link4
		|| list->where != NULL
	 )
		printf("%s \n", str);
	dropped_link->mm.destroy(&dropped_link);
	list->mm.destroy(&list);

	/////////////////////// test first /////////////////////////////

	list = new_double_linked_list();
	link1 = list->mm.add_at_index(list, "0", 2, 0);
	link2 = list->mm.add_at_index(list, "1", 2, 1);
	link3 = list->mm.add_at_index(list, "2", 2, 100);
	link4 = list->mm.add_at_index(list, "3", 2, 100);

	dropped_link = list->mm.drop_link(list, 0, NULL);

	// test le link
	if (1
		&& ft_strcmp(dropped_link->content, "0")
		|| dropped_link->content_size != 2
		|| dropped_link->prev != NULL
		|| dropped_link->next != NULL
		|| dropped_link != link1
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 3
		|| list->head != link2
		|| list->head->next != link3
		|| list->tail != link4
		|| list->where != NULL
	 )
		printf("%s \n", str);

	dropped_link->mm.destroy(&dropped_link);
	list->mm.destroy(&list);

	/////////////////////// test last /////////////////////////////

	list = new_double_linked_list();
	link1 = list->mm.add_at_index(list, "0", 2, 0);
	link2 = list->mm.add_at_index(list, "1", 2, 1);
	link3 = list->mm.add_at_index(list, "2", 2, 100);
	link4 = list->mm.add_at_index(list, "3", 2, 100);

	dropped_link = list->mm.drop_link(list, 110, NULL);

	// test le link
	if (1
		&& ft_strcmp(dropped_link->content, "3")
		|| dropped_link->content_size != 2
		|| dropped_link->prev != NULL
		|| dropped_link->next != NULL
		|| dropped_link != link4
	 )
		printf("%s \n", str);

	// test dll
	if (1
		&& list->length != 3
		|| list->head != link1
		|| list->head->next != link2
		|| list->tail != link3
		|| list->where != NULL
	 )
		printf("%s \n", str);

	dropped_link->mm.destroy(&dropped_link);
	list->mm.destroy(&list);
}

static void test__14_() // test de delete_link_dll
{
	char *str = "test 14 \n test de test de delete_link_dll";
	t_dll list = new_double_linked_list();

	(void) str;
	list->mm.add_begin(list, "42", 3);
	list->mm.delete_link(list, 0, NULL);
	list->mm.destroy(&list);

	list = new_double_linked_list();
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.add_begin(list, "42", 3);
	list->mm.destroy(&list);
}

static void test__15_() // create and destroy 2 circular list
{
	char *str = "test 15 \n test de create and destroy 2 circular list";
	(void) str;
	t_dll cir_list = new_double_linked_list();

	// 1 els
	cir_list->cc.circular_add_begin(cir_list, "0", 3, NULL);
	cir_list->cc.circular_print(cir_list, ' ');
	if (cir_list->length != 1)
		printf("%s \n", str);
	cir_list->cc.circular_destroy(&cir_list);
	printf(" \n");

	// 2 els
	cir_list = new_double_linked_list();
	cir_list->cc.circular_add_begin(cir_list, "0", 3, NULL);
	cir_list->cc.circular_add_begin(cir_list, "1", 3, NULL);
	cir_list->cc.circular_print(cir_list, ' ');
	if (cir_list->length != 2)
		printf("%s \n", str);
	cir_list->cc.circular_destroy(&cir_list);
	printf(" \n");

	// 3 els
	cir_list = new_double_linked_list();
	cir_list->cc.circular_add_begin(cir_list, "0", 3, NULL);
	cir_list->cc.circular_add_begin(cir_list, "1", 3, NULL);
	cir_list->cc.circular_add_begin(cir_list, "2", 3, NULL);
	cir_list->cc.circular_print(cir_list, ' ');
	if (cir_list->length != 3)
		printf("%s \n", str);
	cir_list->cc.circular_destroy(&cir_list);
	printf(" \n");
}

static void test__16_() // test de circular drop
{
	char *str = "test 16 \n test de test de circular drop";
	t_dll cir_list = new_double_linked_list();
	t_dll_l link1;
	t_dll_l link2;
	t_dll_l link3;
	t_dll_l dropped_link;
	t_dll_l dropped_link2;

	// test drop 1  1 --------------------------------------
	link1 = cir_list->cc.circular_add_begin(cir_list, "0", 3, NULL);
	dropped_link = cir_list->cc.circular_drop_link(cir_list);

	if (dropped_link != link1)
		printf("%s \n", str);
	if (1
		&& cir_list->length != 0
		|| cir_list->where != NULL)
		printf("%s \n", str
		);

	cir_list->cc.circular_destroy(&cir_list);
	dropped_link->mm.destroy(&dropped_link);

	// test drop 2   --------------------------------------
	cir_list = new_double_linked_list();
	link1 = cir_list->cc.circular_add_begin(cir_list, "0", 3, NULL);
	link2 = cir_list->cc.circular_add_begin(cir_list, "1", 3, NULL);

	dropped_link = cir_list->cc.circular_drop_link(cir_list);

	if (dropped_link != link1)
		printf("%s \n", str);
	if (1
		&& cir_list->length != 1
		|| cir_list->where != link2)
		printf("%s \n", str
		);

	cir_list->cc.circular_destroy(&cir_list);
	dropped_link->mm.destroy(&dropped_link);

	// test drop 3   --------------------------------------
	cir_list = new_double_linked_list();
	link1 = cir_list->cc.circular_add_begin(cir_list, "0", 3, NULL);
	link2 = cir_list->cc.circular_add_begin(cir_list, "1", 3, NULL);
	link3 = cir_list->cc.circular_add_begin(cir_list, "2", 3, NULL);

	dropped_link = cir_list->cc.circular_drop_link(cir_list);
	dropped_link2 = cir_list->cc.circular_drop_link(cir_list);

	if (dropped_link != link1)
		printf("%s \n", str);
	if (dropped_link2 != link2)
		printf("%s \n", str);

	if (1
		&& cir_list->length != 1
		|| cir_list->where != link3)
		printf("%s \n", str
		);

	cir_list->cc.circular_destroy(&cir_list);
	dropped_link->mm.destroy(&dropped_link);
	dropped_link2->mm.destroy(&dropped_link2);
}

static void test__17_() // test put de list a list 
{
	char *str = "test 17 \n test de test put de list a list ";
	(void) str;
	t_dll cir_list_a = new_double_linked_list();
	t_dll cir_list_b = new_double_linked_list();

	t_dll_l link1;
	t_dll_l link2;
	t_dll_l link3;
	t_dll_l dropped_link1;

	link1 = cir_list_a->cc.circular_add_begin(cir_list_a, "0", 3, NULL);
	link2 = cir_list_a->cc.circular_add_begin(cir_list_a, "1", 3, NULL);
	link3 = cir_list_a->cc.circular_add_begin(cir_list_a, "2", 3, NULL);

	dropped_link1 = cir_list_a->cc.circular_drop_link(cir_list_a);
	cir_list_b->cc.circular_add_begin(cir_list_b, "", 0,
									  dropped_link1);
	dropped_link1 = cir_list_a->cc.circular_drop_link(cir_list_a);
	cir_list_b->cc.circular_add_begin(cir_list_b, "", 0,
									  dropped_link1);
	dropped_link1 = cir_list_a->cc.circular_drop_link(cir_list_a);
	cir_list_b->cc.circular_add_begin(cir_list_b, "", 0,
									  dropped_link1);
	cir_list_b->cc.circular_print(cir_list_b, ' ');
	cir_list_b->cc.circular_print(cir_list_a, ' ');

	cir_list_a->cc.circular_destroy(&cir_list_a);
	cir_list_b->cc.circular_destroy(&cir_list_b);
}

static int func_test__18(t_dll_l link, int nb)
{
	if (link->mm.get_content_int(link) == nb)
	{
		return (TRUE);;
	}
	return (FALSE);
}

static void test__18_() // test de la circular_find_by_nb
{
	char *str = "test 18 \n test de test de la fonction pour les lists circulaire douiblement cahimer ";

	(void) str;
	t_dll cir_list_a = new_double_linked_list();

	t_dll_l link1;
	t_dll_l link2;
	t_dll_l link3;
	t_dll_l tmp;
	int a = 0;
	int b = 1;
	int c = 2;

	link1 = cir_list_a->cc.circular_add_begin(cir_list_a, &a, sizeof(int),
											  NULL);
	link2 = cir_list_a->cc.circular_add_begin(cir_list_a, &b, sizeof(int),
											  NULL);
	link3 = cir_list_a->cc.circular_add_begin(cir_list_a, &c, sizeof(int),
											  NULL);

//	cir_list_a->cc.print_circular_nb(cir_list_a,' ');
	tmp = cir_list_a->cc.circular_find_by_nb(cir_list_a, 1, &func_test__18);
	if (tmp == NULL)
		printf("%d \n", tmp->mm.get_content_int(tmp));

	tmp = cir_list_a->cc.circular_find_by_nb(cir_list_a, 100, &func_test__18);
	if (tmp != NULL)
		printf("%d \n", tmp->mm.get_content_int(tmp));
}

void test_double_linked_list()
{
	test__1_();
	test__2_();
	test__3_();
	test__4_();
	test__5_();
	test__6_();
	test__7_();
	test__8_();
	test__9_();
	test__10_();
	test__11_();
	test__12_();
	test__13_();
	test__14_();
	test__15_();
	test__16_();
	test__17_();
	printf("\n------------------------ \n");
	test__18_();
}

int main()
{
	test_double_linked_list();

	return (42);
}