cmake_minimum_required(VERSION 3.9)
project(push_swap C)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")


#include_directories(${PROJECT_SOURCE_DIR}/include)

#*------------------------------------*\
#    --  PATH  --
#*------------------------------------*/
set(REPO "push_swap")
set(LIBFT "${REPO}/libft")

#*------------------------------------*\
#    --  THE HEADERS --
#*------------------------------------*/
file(GLOB head "${REPO}/includes/*.h")
#include_directories("${REPO}/includes/*.h")

#*------------------------------------*\
#    -- LIB FT FILE --
#*------------------------------------*/
file(GLOB sources0 "${LIBFT}/src/*.c")
file(GLOB sources1 "${LIBFT}/src/**/*.c")
file(GLOB sources2 "${LIBFT}/src/**/**/*.c")
file(GLOB sources3 "${LIBFT}/src/**/**/**/*.c")
file(GLOB sources4 "${LIBFT}/src/**/**/**/**/*.c")
file(GLOB sources5 "${LIBFT}/**/**/**/**/**/*.c")
file(GLOB sources6 "${LIBFT}/test/*.c")

#*------------------------------------*\
#    --  PROJET FILE  --
#*------------------------------------*/
file(GLOB sources00 "${REPO}/src/*.c")
file(GLOB sources01 "${REPO}/**/*.c")
file(GLOB sources02 "${REPO}/**/**/*.c")
file(GLOB sources03 "${REPO}/**/**/**/*.c")
file(GLOB sources04 "${REPO}/**/**/**/**/*.c")
file(GLOB sources05 "${REPO}/**/**/**/**/**/*.c")


#*------------------------------------*\
#    --  TEST FILE  --
#*------------------------------------*/
file(GLOB sources06 "test/*.c")
#file(GLOB sources07 "includes/*.c")
#file(GLOB sources08 "includes/*.h")

#*------------------------------------*\
#    --  MIXE ALL SOURCES  --
#*------------------------------------*/
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
        #        ${sources07}
        #        ${sources08}
)

#*------------------------------------*\
#    --  ADD TO PROGRAMME  --
#*------------------------------------*/

add_executable(
        push_swap
        main.c
        ${sources}
        ${head}
)

#*------------------------------------*\
#    --  LINK OTHER LIB  --
#*------------------------------------*/
#target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/lib/mlx/libmlx.a)
#target_link_libraries(push_swap "-framework OpenGL")
#target_link_libraries(push_swap "-framework AppKit")

