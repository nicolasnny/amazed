##
## EPITECH PROJECT, 2023
## makefile miniprintf
## File description:
## Makefile for miniprintd
##

CC	=	gcc

SRC	=	src/main.c	\
		src/get_data.c			\
		src/amazed.c			\
		src/store_data.c	\
		src/algo.c	\
		src/linked_list.c	\
		src/node.c	\
		src/clean.c	\
		src/error_handling.c	\
		src/path.c	\
		src/key.c	\
		src/boxes.c	\
		src/game_loop.c	\

UT_SRC	=	tests/unit_tests.c	\
		src/get_data.c			\
		src/amazed.c			\
		src/store_data.c	\
		src/algo.c	\
		src/linked_list.c	\
		src/node.c	\
		src/clean.c	\
		src/error_handling.c	\
		src/path.c	\
		src/key.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	amazed

UT_BIN	=	unit_tests

CPPFLAGS	=	-iquote./include

CFLAGS	=	-Wall -Wextra

LDFLAGS =	-L./lib/my

UT_FLAGS	=	--coverage -lcriterion

LDLIBS	=	-lmy

LIBNAME	=	libmy.a

CS_CLEAN = *.log

CS_REPORT = coding-style-reports.log

UT_CLEAN	=	*.gcda *.gcno

all:	lib $(NAME)

lib:
	$(MAKE) -C lib/my

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(MAKE) clean -C lib/my
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/my/$(LIBNAME)
	$(RM) $(CS_CLEAN)
	$(RM) $(UT_CLEAN)
	$(RM) $(UT_BIN)

re:	fclean all

valgrind : CFLAGS += -g3
valgrind : re

asan:	CC	=	clang -fsanitize=address
asan:	CFLAGS += -ggdb3
asan:	re

gdb: valgrind
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" $(NAME)

tests_run:	fclean re
	gcc -o $(UT_BIN) $(UT_SRC) -I include/ -L . -lhashtable $(UT_FLAGS)
	./$(UT_BIN)

coding_style:	fclean
	coding-style . . > /dev/null 2>&1
	cat $(CS_REPORT)
	make fclean  > /dev/null 2>&1

tests_run:	fclean lib
	$(CC) -I include/ -L ./lib/my -o $(UT_BIN) $(UT_SRC) $(UT_FLAGS) -lmy
	./$(UT_BIN)

.PHONY: all clean fclean re valgrind asan coding_style	gdb tests_run lib

.SILENT: coding_style
