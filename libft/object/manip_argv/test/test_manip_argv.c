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

#include "../../../../includes/libft.h"
#include "../argv/header/header_argv.h"

static void test__1_() // test construct argv
{
	char *str = "test 1 \n test de test de argv";
	char **av = ft_strsplit("namepg 1", ' ');

	t_argv argv = new_argv(4, av);

	if (1
		&& argv->av != av
		|| argv->ac != 4
		|| argv->str_options[0] != 0
	 )
	{
		printf("%s \n", str);
	}
	ft_free_split(&av);
	argv->mm.destroy(&argv);
}

static void test__2_()
{
	char *str = "test 1.1 avec aucun arguments";

	char **av_main = ft_strsplit("8", ' ');
	t_get_op get_op;
	t_argv argv;

	get_op = new_get_op(1, av_main);
	argv = get_op->mm.get_option(get_op);

	if (argv->count != 1)
		printf("%s \n", str);

	ft_free_split(&av_main);
	argv->mm.destroy(&argv);
	get_op->mm.destroy(&get_op);
}

static void test__3_() // 2 arguments
{
	char *str = "test 3 \n test de 2 arguments";

	char **av_main = ft_strsplit("8 -f -o -t", ' ');
	t_get_op get_op;
	t_argv argv;

	get_op = new_get_op(3, av_main);
	argv = get_op->mm.get_option(get_op);

	if (1
		&& ft_strcmp(argv->str_options, "fo")
		|| argv->count != 3
		|| argv->av[0] != av_main[0]
	 )
		printf("%s \n",str);

		ft_free_split(&av_main);
	argv->mm.destroy(&argv);
	get_op->mm.destroy(&get_op);
}

static void test__4_() // pas d'option valable
{
	char *str="test 4 \n test de pas d'option valable";

	char **av_main = ft_strsplit("8 -sf -e -t", ' ');
	t_get_op get_op;
	t_argv argv;

	get_op = new_get_op(4, av_main);
	argv = get_op->mm.get_option(get_op);

	if (1
		&& ft_strcmp(argv->str_options, "")
		|| argv->count != 1
		|| argv->av[0] != av_main[0]
	 )
		printf("%s \n",str);

	ft_free_split(&av_main);
	argv->mm.destroy(&argv);
	get_op->mm.destroy(&get_op);

}

void test__all_argv_() //
{
	test__1_();
	test__2_();
	test__3_();
	test__4_();
}

//int main()
//{
//	test__all_argv_();
//	return (0);
//}