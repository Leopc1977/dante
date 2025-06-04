
SRC = $(wildcard src/utils/*.c) \
	src/main.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc -o

NAME		=	solver

INCLUDE		=	-I include

CFLAGS		+=	-Wall -Werror -Wextra

CPPFLAGS	+=	$(INCLUDE) -Ofast

LDFLAGS		+=	-lm

REMOVE		=	rm -f

BUILD		=	make -C

M_CLEAN		=	clean

M_FCLEAN	=	fclean

ALL		=	all

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LDFLAGS)

clean:
		$(REMOVE) $(OBJ)

fclean:		$(M_CLEAN)
		$(REMOVE) $(NAME)

re:		$(M_FCLEAN) $(ALL)

run: re
	./solver ./test.txt

.PHONY:		$(ALL) $(M_CLEAN) $(M_FCLEAN) re