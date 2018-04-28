.PHONY: all, $(NAME), clean, fclean, re



NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra




# source folder set
SRC_DIR = src/

LIBFT_DIR = $(SOURCES_FILE)sources/

HEADER_DIR = header/

SOURCES_FILE = src/

#OBJ_DIR = $(SOURCES_FILE)obs/

# name file set
SRC = build_list_a_index.c checker/main_checker.c commun_all_prg.c debug.c getter_data/get_list_a.c getter_data/getter_is_good_nb.c getter_data/getter_utils.c is_just_three.c solver/browse/browse_simple.c solver/browse/first_browser.c solver/get_median.c solver/main_solver.c solver/push_new_instruct.c solver/quick/get_med_quick.c solver/quick/quick.c solver/quick/set_and_get_quick.c solver/sort/manage_sort.c solver/sort/sort_3_and_2.c solver/sort/sort_4.c solver/sort/sort_bower.c stack/construct_stack.c stack/src/pile_p.c stack/src/pile_r.c stack/src/pile_rr.c stack/src/pile_s.c stack/src/swap.c

OBJS = $(addprefix $(SRC_DIR),$(SRC:.c=.o))


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./$(LIBFT_DIR) -lft


%.o: %.c
	@gcc $(FLAG) -o $@ -c $<

clean:..
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
	@/bin/rm -rf $(OBJS)


#	-I $(LIBFT_DIR)ft_library_header.h