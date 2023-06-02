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
	swap.c \

SRCS_BONUS= checker.c \
	list_bonus.c \
	push_bonus.c \
	swap_bonus.c \
	rotate_bonus.c \
	parsing_bonus.c \
	parsing_utils_bonus.c \
	reverse_rotate_bonus.c \
	push_swap_utils_bonus.c \
	get_next_line.c \
	get_next_line_utils.c \

OBJS= ${SRCS:.c=.o}

OBJS_BONUS= ${SRCS_BONUS:.c=.o}

CC= cc

FLAGS= -Wall -Werror -Wextra -g3

RM= rm -f

all: $(NAME)

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

bonus: ${OBJS_BONUS}
	${CC} ${FLAGS} ${OBJS_BONUS} -o checker

AR= ar rcs

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} checker

re: fclean all

.PHONY: all clean fclean re
