cmake_minimum_required(VERSION 3.9)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB head "includes/*.h")
#include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(includes/*.h)

file(GLOB sources0 "src/*.c")
file(GLOB sources1 "lib/libft/src/**/*.c")
file(GLOB sources2 "lib/libft/src/**/**/*.c")
file(GLOB sources3 "lib/libft/src/**/**/**/*.c")
file(GLOB sources4 "lib/libft/src/**/**/**/**/*.c")
file(GLOB sources5 "lib/libft/src/**/**/**/**/**/*.c")
file(GLOB sources6 "test/*.c")


file(GLOB sources00 "src/*.c")
file(GLOB sources01 "src/**/*.c")
file(GLOB sources02 "src/**/**/*.c")
file(GLOB sources03 "src/**/**/**/*.c")
file(GLOB sources04 "src/**/**/**/**/*.c")
file(GLOB sources05 "src/**/**/**/**/**/*.c")

file(GLOB sources06 "test/*.c")

file(GLOB sources07 "includes/*.c")
file(GLOB sources08 "includes/*.h")

# all sources
set(
        sources
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}

        ${sources00}
        ${sources01}
        ${sources02}
        ${sources03}
        ${sources04}
        ${sources05}
        ${sources06}
        ${sources07}
        ${sources08}

)

add_executable(push_swap
        main.c
        ${sources}
        ${head}
        )

target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/lib/mlx/libmlx.a)
target_link_libraries(push_swap "-framework OpenGL")
target_link_libraries(push_swap "-framework AppKit")

