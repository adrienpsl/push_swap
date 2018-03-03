cmake_minimum_required(VERSION 3.8)
project(libft)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB SRC
        "includes/**"
        "src/**"
        )

message("${helloworld_SRC}")

set(SOURCE_FILES
        main.c
#        header
        includes/libft.h
#
#        files
        src/fonction/buffer_str/ft_buff_addchar_str.c src/fonction/buffer_str/ft_buffset_orprint_str.c src/fonction/buffer_str/ft_fill_buff_str.c src/fonction/buffer_str/ft_print_buff_str.c src/fonction/buffer_str/ft_set_buffer_str.c src/fonction/char/ft_free_doublechar_tab.c src/fonction/char/ft_isalnum.c src/fonction/char/ft_isalpha.c src/fonction/char/ft_isascii.c src/fonction/char/ft_isdigit.c src/fonction/char/ft_isprint.c src/fonction/char/ft_put_uni.c src/fonction/char/ft_putchar.c src/fonction/char/ft_putchar_fd.c src/fonction/char/ft_tolower.c src/fonction/char/ft_toupper.c src/fonction/debug/debug_str.c src/fonction/list/s_list/ft_lst_reverse.c src/fonction/list/s_list/ft_lstadd.c src/fonction/list/s_list/ft_lstdel.c src/fonction/list/s_list/ft_lstdelone.c src/fonction/list/s_list/ft_lstiter.c src/fonction/list/s_list/ft_lstmap.c src/fonction/list/s_list/ft_lstnew.c src/fonction/memory/ft_bzero.c src/fonction/memory/ft_exit_lack_memory.c src/fonction/memory/ft_malloc_protect.c src/fonction/memory/ft_memalloc.c src/fonction/memory/ft_memccpy.c src/fonction/memory/ft_memchr.c src/fonction/memory/ft_memcmp.c src/fonction/memory/ft_memcpy.c src/fonction/memory/ft_memdel.c src/fonction/memory/ft_memmove.c src/fonction/memory/ft_memset.c src/fonction/memory/soa.c src/fonction/nb/ft_atoi.c src/fonction/nb/ft_putnbr.c src/fonction/nb/ft_putnbr_fd.c src/fonction/sort/ft_quick_sort.c src/fonction/str/check_char_into_str.c src/fonction/str/ft_free_split.c src/fonction/str/ft_is_all_number.c src/fonction/str/ft_itoa.c src/fonction/str/ft_putendl.c src/fonction/str/ft_putendl_fd.c src/fonction/str/ft_putstr.c src/fonction/str/ft_putstr_fd.c src/fonction/str/ft_str_rev.c src/fonction/str/ft_strcat.c src/fonction/str/ft_strchr.c src/fonction/str/ft_strchr_dup.c src/fonction/str/ft_strchr_how_many.c src/fonction/str/ft_strchr_len.c src/fonction/str/ft_strclr.c src/fonction/str/ft_strcmp.c src/fonction/str/ft_strcpy.c src/fonction/str/ft_strdel.c src/fonction/str/ft_strdup.c src/fonction/str/ft_strequ.c src/fonction/str/ft_striter.c src/fonction/str/ft_striteri.c src/fonction/str/ft_strjoin.c src/fonction/str/ft_strlcat.c src/fonction/str/ft_strlen.c src/fonction/str/ft_strmap.c src/fonction/str/ft_strmapi.c src/fonction/str/ft_strncat.c src/fonction/str/ft_strncmp.c src/fonction/str/ft_strncpy.c src/fonction/str/ft_strndup.c src/fonction/str/ft_strnequ.c src/fonction/str/ft_strnew.c src/fonction/str/ft_strnjoin.c src/fonction/str/ft_strnstr.c src/fonction/str/ft_strrchr.c src/fonction/str/ft_strsplit.c src/fonction/str/ft_strstr.c src/fonction/str/ft_strsub.c src/fonction/str/ft_strtrim.c src/fonction/str/get_last_char_str.c src/fonction/str/index_of_char.c src/fonction/str/str_by_func.c src/objet/list/double_linked_list_link/dll_l_construct.c src/objet/list/double_linked_list_link/src/dll_l_get_content.c
        src/objet/list/double_linked_list_link/test/dll_l_.test.c src/objet/list/double_linked_list_circular/dll_c_construct.c includes/src/dll_c_header.h src/objet/list/double_linked_list_circular/test/dll_c.test.c src/objet/list/double_linked_list_circular/src/dll_c_push_link.c src/objet/list/double_linked_list_circular/debug/dll_c_debug_print.c src/objet/list/double_linked_list_circular/src/dll_c_drop_link.c src/objet/list/double_linked_list_circular/src/dll_c_iter.c includes/src/argv_header.h src/objet/argv/argv_contruct.c src/objet/argv/test/argv.test.c src/objet/argv/src/get_next_argv_1.c src/objet/argv/src/argv_utils.c src/objet/argv/src/get_next_argv_2.c src/objet/argv/src/argv_get_option.c src/objet/argv/src/argv_go_prev_argv.c)
add_executable(libft ${SOURCE_FILES} ${SRC})