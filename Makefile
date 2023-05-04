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

SRCS=  cost.c\
	indexing.c \
	list.c \
	make_shifts.c \
	parsing_utils.c \
	parsing.c \
	position.c \
	push_swap_utils.c \
	push_swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	sort.c \
	swap.c

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
