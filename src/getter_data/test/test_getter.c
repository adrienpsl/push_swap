#include "../../../header/getter_header.h"

void static init()
{
}

void static destroy()
{
}

static void test__1_() // test avec good nb
{
	init();
	t_dll_c c_list = new_dll_c();
	t_dll_l link;
	int a;

	char **nb = ft_strsplit("44646546 002 3 4 5 0 ", ' ');

	for (int i = 0; i < 6; ++i)
	{
		if ((a = is_valide_number(nb[i], c_list)))
		{
			link = new_dll_l(&a, sizeof(int));
			dll_c_push_link(link, c_list);
		}
	}

	destroy();
}

static void test__2_(int ac, char **av) // check si destruct et constr
{
	t_argv argv = new_argv(ac, av);
	t_dll_c c_list = new_dll_c();
	t_dll_l link;
	int a;
	char *nb_str;

	while (argv_get_next_argv(&nb_str,argv))
	{
		if (is_action(nb_str))
			break;
		if ((a = is_valide_number(nb_str, c_list)))
		{
			link = new_dll_l(&a, sizeof(int));
			dll_c_push_link(link, c_list);;
		}
	}
}

static void test__3_(int ac, char **av) // check si destruct et constr
{
	t_argv argv = new_argv(ac, av);
	t_dll_c c_list = get_list_a(argv, 1);
	printf("%s \n",argv->av[argv->counter]);
	(void) c_list;
}

void all_test_getter(int ac, char **av)
{
	test__1_();
	test__2_(ac, av);
	test__3_(ac, av);
}

//int main(int ac, char **av)
//{
//	all_test_getter(ac, av);
//	return (0);
//}


// check la diff entre les deux pour les argv