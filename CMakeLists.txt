cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB head "header/*.h")
include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(sources/include/*.h)
file(GLOB sources1 "sources/src/**/*.c")
file(GLOB sources2 "sources/src/**/**/*.c")
file(GLOB sources3 "sources/src/**/**/**/*.c")
file(GLOB sources4 "sources/src/**/**/**/**/*.c")
file(GLOB sources5 "sources/src/**/**/**/**/**/*.c")
file(GLOB sources6 "test/*.c")

# all sources
set(
        sources
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}
        src/solver/build_list_a_index.c src/solver_v1/src/median_calculation.c src/solver_v1/src/search_utils.c src/solver_v1/src/push_in_b/push_in_b.c debug.c src/solver_v1/src/push_in_b/push_in_b_utils.c src/solver_v1/src/manip_list_instruct/push_new_instruct.c src/commun_all_prg.c src/solver_v1/src/push_in_b/nb_isnt_limit.c src/solver_v1/src/push_in_b/find_up_down.c src/solver/main_solver.c src/solver/who_s_the_best.c)


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

