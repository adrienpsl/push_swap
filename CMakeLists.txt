cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

add_executable(push_swap main.c reader/reader.c push_swap/push_swap.h push_swap/main_push_swap.c push_swap/utils/utils_main_pw.c utils_all.c reader/utils.c)

target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)
