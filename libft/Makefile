.PHONY: all, $(NAME), clean, fclean, re

NAME = libft.a
PATH_SRC = src/
HEADER = ./includes/libft.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
DO_IN_SHELL = cd src ; find . -type f -name '*.c' | tr '\n' ' ' | pbcopy
SR = ./fonction/buffer_str/ft_buff_addchar_str.c ./fonction/buffer_str/ft_buffset_orprint_str.c ./fonction/buffer_str/ft_fill_buff_str.c ./fonction/buffer_str/ft_print_buff_str.c ./fonction/buffer_str/ft_set_buffer_str.c ./fonction/char/ft_free_doublechar_tab.c ./fonction/char/ft_isalnum.c ./fonction/char/ft_isalpha.c ./fonction/char/ft_isascii.c ./fonction/char/ft_isdigit.c ./fonction/char/ft_isprint.c ./fonction/char/ft_put_uni.c ./fonction/char/ft_putchar.c ./fonction/char/ft_putchar_fd.c ./fonction/char/ft_tolower.c ./fonction/char/ft_toupper.c ./fonction/debug/debug_str.c ./fonction/list/s_list/ft_lst_reverse.c ./fonction/list/s_list/ft_lstadd.c ./fonction/list/s_list/ft_lstdel.c ./fonction/list/s_list/ft_lstdelone.c ./fonction/list/s_list/ft_lstiter.c ./fonction/list/s_list/ft_lstmap.c ./fonction/list/s_list/ft_lstnew.c ./fonction/memory/ft_bzero.c ./fonction/memory/ft_exit_lack_memory.c ./fonction/memory/ft_malloc_protect.c ./fonction/memory/ft_memalloc.c ./fonction/memory/ft_memccpy.c ./fonction/memory/ft_memchr.c ./fonction/memory/ft_memcmp.c ./fonction/memory/ft_memcpy.c ./fonction/memory/ft_memdel.c ./fonction/memory/ft_memmove.c ./fonction/memory/ft_memset.c ./fonction/memory/soa.c ./fonction/nb/ft_atoi.c ./fonction/nb/ft_putnbr.c ./fonction/nb/ft_putnbr_fd.c ./fonction/sort/ft_quick_sort.c ./fonction/str/check_char_into_str.c ./fonction/str/ft_free_split.c ./fonction/str/ft_is_all_number.c ./fonction/str/ft_itoa.c ./fonction/str/ft_putendl.c ./fonction/str/ft_putendl_fd.c ./fonction/str/ft_putstr.c ./fonction/str/ft_putstr_fd.c ./fonction/str/ft_str_rev.c ./fonction/str/ft_strcat.c ./fonction/str/ft_strchr.c ./fonction/str/ft_strchr_dup.c ./fonction/str/ft_strchr_how_many.c ./fonction/str/ft_strchr_len.c ./fonction/str/ft_strclr.c ./fonction/str/ft_strcmp.c ./fonction/str/ft_strcpy.c ./fonction/str/ft_strdel.c ./fonction/str/ft_strdup.c ./fonction/str/ft_strequ.c ./fonction/str/ft_striter.c ./fonction/str/ft_striteri.c ./fonction/str/ft_strjoin.c ./fonction/str/ft_strlcat.c ./fonction/str/ft_strlen.c ./fonction/str/ft_strmap.c ./fonction/str/ft_strmapi.c ./fonction/str/ft_strncat.c ./fonction/str/ft_strncmp.c ./fonction/str/ft_strncpy.c ./fonction/str/ft_strndup.c ./fonction/str/ft_strnequ.c ./fonction/str/ft_strnew.c ./fonction/str/ft_strnjoin.c ./fonction/str/ft_strnstr.c ./fonction/str/ft_strrchr.c ./fonction/str/ft_strsplit.c ./fonction/str/ft_strstr.c ./fonction/str/ft_strsub.c ./fonction/str/ft_strtrim.c ./fonction/str/get_last_char_str.c ./fonction/str/index_of_char.c ./fonction/str/str_by_func.c ./objet/argv/argv_contruct.c ./objet/argv/src/argv_get_option.c ./objet/argv/src/argv_go_prev_argv.c ./objet/argv/src/argv_utils.c ./objet/argv/src/get_next_argv_1.c ./objet/argv/src/get_next_argv_2.c ./objet/argv/test/argv.test.c ./objet/list/double_linked_list_circular/debug/dll_c_debug_print.c ./objet/list/double_linked_list_circular/dll_c_construct.c ./objet/list/double_linked_list_circular/src/dll_c_drop_link.c ./objet/list/double_linked_list_circular/src/dll_c_iter.c ./objet/list/double_linked_list_circular/src/dll_c_push_link.c ./objet/list/double_linked_list_circular/test/dll_c.test.c ./objet/list/double_linked_list_link/dll_l_construct.c ./objet/list/double_linked_list_link/src/dll_l_get_content.c ./objet/list/double_linked_list_link/test/dll_l_.test.c
SRC = $(addprefix src/, $(SR))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^

%.o: %.c
	@gcc $(FLAG) -o $@ -c $<

clean:..
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
	@/bin/rm -rf $(OBJ)