cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

#set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB head "header/*.h")
include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(src/sources/include/*.h)
file(GLOB sources1 "src/sources/src/**/*.c")
file(GLOB sources2 "src/sources/src/**/**/*.c")
file(GLOB sources3 "src/sources/src/**/**/**/*.c")
file(GLOB sources4 "src/sources/src/**/**/**/**/*.c")
file(GLOB sources5 "src/sources/src/**/**/**/**/**/*.c")
file(GLOB sources6 "test/*.c")

# all sources
set(
        src/sources
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}
        src/build_list_a_index.c src/solver_v1/src/median_calculation.c src/solver_v1/src/search_utils.c src/solver_v1/src/push_in_b/push_in_b.c debug.c src/solver_v1/src/push_in_b/push_in_b_utils.c src/solver/push_new_instruct.c src/commun_all_prg.c src/solver_v1/src/push_in_b/nb_isnt_limit.c src/solver_v1/src/push_in_b/find_up_down.c src/solver/main_solver.c src/solver/quick/quick.c src/solver/sort_v1/short.c src/stack/src/swap.c src/solver/sort_v1/sort_4_top_b_suite.c src/solver/sort_v1/sort_4_top_b.c src/solver/sort_v1/short_3_front.c src/solver/sort_v1/sort_4_top_a.c src/solver/sort_v1/sort_4_top_a_suite.c src/solver/sort_v1/sort_4_top.c src/solver/sort/sort_4.c src/solver/sort/sort_3_and_2.c src/solver/browse/browse_simple.c src/solver/sort/sort_bower.c src/solver/browse/first_browser.c src/solver/quick/set_and_get_quick.c src/solver/quick/get_med_quick.c src/solver/get_median.c src/solver/sort/manage_sort.c src/is_just_three.c src/is_nine.c)


add_executable(push_swap

        main.c
        ${sources}
        ${head}

        test/getter_test.c
        src/getter_data/getter_is_good_nb.c
        src/getter_data/getter_utils.c
        src/stack/construct_stack.c
        src/checker/main_checker.c
        test/checker_test.c
        src/getter_data/get_list_a.c
        src/stack/src/pile_s.c
        src/stack/src/pile_p.c
        src/stack/src/pile_r.c
        src/stack/src/pile_rr.c
        test/pile_test.c
        src/solver_v1/main_solver.c
        header/debug.c)

