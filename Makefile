.PHONY: all, $(NAME), clean, fclean, re

NAME = push_swap.a
PATH_SRC = src/
HEADER = ./includes/libft.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
DO_IN_SHELL = cd src ; find . -type f -name '*.c' | tr '\n' ' ' | pbcopy
SR = ./checker/main_checker.c ./checker/src/checker_src.c ./checker/test/test_checker.c ./getter_data/get_list_a.c ./getter_data/src/getter_is_good_nb.c ./getter_data/test/test_getter.c ./getter_data/utils/utils.c ./stack/construct_pile.c ./stack/src/pile_p.c ./stack/src/pile_r.c ./stack/src/pile_rr.c ./stack/src/pile_s.c ./stack/test/test_pile.c
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