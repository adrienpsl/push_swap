cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB SRC
        "checker/**"
#        "checker/**/**"
#        "checker/**/**/**"
        )

add_executable(push_swap ${SRC}

        checker/getter_data/header_getter_data.h
        main.c checker/getter_data/header_getter_data.c checker/getter_data/header_getter_data.h checker/checker.h checker/test/test_getter.c checker/getter_data/src/getter_is_good_nb.c checker/getter_data/utils/utils.c checker/getter_data/src/push_nb.c)

target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)
