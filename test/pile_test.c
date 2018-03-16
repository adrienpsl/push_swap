#include "../header/all_includes.h"

t_stack test_stack;

void static init()
{
	test_stack = new_stack();
	test_stack->pile_a = new_dll_c();
}

void static destroy()
{
	destroy_stack(&test_stack);
}

static void test__1_() // check si destruct et construct work
{
	init();
	destroy();
}

void all_test_stack()
{
    test__1_();
}

//int main()
//{
//	all_test_stack();
//	return (0);
//}
