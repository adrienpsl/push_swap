cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

add_executable(push_swap main.c push_swap/reader/reader.c push_swap.h push_swap/push_swap.c push_swap/utils_pw.c utils_projet.c checker/utils.c checker/main_checker.c checker/checker_reader.c do_commande/exange.c do_commande/push_pile.c do_commande/rev.c do_commande/reverse.c push_swap/solver/solver.c push_swap/solver/utils_solver.c)

target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)
