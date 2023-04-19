NAME= push_swap

SRCS= shifts.c parsing.c presort.c push_swap_utils.c push_swap.c retrieving.c sorting_utils.c switchcount.c push.c swap.c rotate.c reverse_rotate.c
		

OBJS= ${SRCS:.c=.o}

CC= cc

FLAGS= -Wall -Werror -Wextra -g3

RM= rm -f

all: $(NAME)

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

AR= ar rcs

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re