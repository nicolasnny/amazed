##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Write a Makefile that compiles your libmy.
## It should perform the following actions:
##

CC	=	gcc

SRC	=	my_char_not_in_str.c		\
		my_print_str_array.c		\
		my_strdup.c					\
		my_strncmp.c				\
		my_str_array_cpy.c			\
		my_str_array_dup.c			\
		my_free_str_array.c			\
		my_sort_int_array.c			\
		my_putchar.c				\
		my_strstr.c					\
		my_strcat.c					\
		my_putstr.c					\
		my_strcmp.c					\
		my_strlen.c 				\
		my_getnbr.c					\
		my_str_isnum.c				\
		my_revstr.c					\
		my_strcpy.c					\
		my_strstrlen.c				\
		my_str_to_word_array.c		\
		my_free_n_str.c				\
		my_str_from_char.c			\
		my_strn_array_dup.c			\
		mini_printf.c				\
		my_putstr_err.c	\
		my_putchar_err.c	\
		find_str.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

HFILE	=	my.h

BIN_NAME	=	amazed

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

run:
	gcc -o $(BIN_NAME) $(CFLAGS) main.c -L./ -lmy

copy:
	cp libmy.a  ../libmy.a
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

valgrind : CFLAGS += -g3
valgrind : re

asan:	CC	=	clang -fsanitize=address
asan:	CFLAGS += -ggdb3
asan:	re

gdb: valgrind
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" $(BIN_NAME)

re:	fclean all

.PHONY: all copy clean fclean debug re
