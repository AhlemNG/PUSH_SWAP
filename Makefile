# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anouri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 11:54:13 by anouri            #+#    #+#              #
#    Updated: 2023/04/29 11:54:18 by anouri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRCS= shifts.c parsing.c presort.c push_swap_utils.c push_swap.c retrieving.c indexing.c switchcount.c push.c swap.c rotate.c reverse_rotate.c make_shifts.c
		

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
