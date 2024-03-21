##
## EPITECH PROJECT, 2023
## makefile miniprintf
## File description:
## Makefile for miniprintd
##

SRC	=	src/main.c	\
		src/store_data.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	amazed

CPPFLAGS	=	-iquote./include

CFLAGS	=	-Wall -Wextra

LDFLAGS =	-L./lib/my

LDLIBS	=	-lmy

LIBNAME	=	libmy.a

CS_CLEAN = *.log

CS_REPORT = coding-style-reports.log

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(MAKE) clean -C lib/my
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/my/$(LIBNAME)
	$(RM) $(CS_CLEAN)

re:	fclean all

valgrind : CFLAGS += -g3
valgrind : re

asan:	CC	=	clang -fsanitize=address
asan:	CFLAGS += -ggdb3
asan:	re

gdb: debug
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" $(NAME)

coding_style:	fclean
	coding-style . . > /dev/null 2>&1
	cat $(CS_REPORT)
	make fclean  > /dev/null 2>&1

.PHONY: all clean fclean re valgrind asan coding_style	gdb

.SILENT: coding_style
