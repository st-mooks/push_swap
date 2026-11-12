# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 16:02:50 by mbadarin          #+#    #+#              #
#    Updated: 2026/11/12 16:02:54 by mbadarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=				push_swap
BONUS_NAME:=		checker
CC:= 				cc
CFLAGS:=			-Wall -Werror -Wextra
PUSH_SWAP_PATH:= 	.
ALGORITHM_PATH:=	${PUSH_SWAP_PATH}/algorithm
OPERATIONS_PATH:=	${PUSH_SWAP_PATH}/operations
UTILS_PATH:=		${PUSH_SWAP_PATH}/utils
LIBFT_PATH:=		${PUSH_SWAP_PATH}/libft
BONUS_PATH:=		${PUSH_SWAP_PATH}/bonus
MAIN:=				${PUSH_SWAP_PATH}/main.c
SOURCES:=			${ALGORITHM_PATH}/simple.c\
					${OPERATIONS_PATH}/a_ops.c\
					${OPERATIONS_PATH}/b_ops.c\
					${OPERATIONS_PATH}/ab_ops.c\
					${OPERATIONS_PATH}/push_swap.c\
					${OPERATIONS_PATH}/rotate.c\
					${UTILS_PATH}/disorder.c\
					${UTILS_PATH}/input_parsing.c\
					${UTILS_PATH}/list_functions.c\
					${UTILS_PATH}/ops_utils.c\
					${UTILS_PATH}/print_utils.c\
					${UTILS_PATH}/split_input.c\
					${UTILS_PATH}/validation.c
BONUS_MAIN:=		${BONUS_PATH}/main.c
BONUS_SOURCES:=		${BONUS_PATH}/utils.c
OBJECTS:=			${SOURCES:.c=.o}
BONUS_OBJECTS:=		${BONUS_SOURCES:.c=.o}
HEADER:=			push_swap.h
BONUS_HEADER:=		${BONUS_PATH}\push_swap_bonus.h
all: ${NAME}
${NAME}: ${MAIN} ${OBJECTS} 
	${CC} ${CFLAGS} $^ -L${LIBFT_PATH} -lft -o ${NAME} 
bonus: ${BONUS_MAIN} ${BONUS_OBJECTS} ${OBJECTS}
	${CC} ${CFLAGS} $^ -L${LIBFT_PATH} -lft -o ${BONUS_NAME}
%.c: %.o ${HEADER} ${BONUS_HEADER}
	${CC} ${CFLAGS} $< -c $@
clean:
	rm -f ${OBJECTS} ${BONUS_OBJECTS}
fclean: clean
	rm -f ${NAME} ${BONUS_NAME}
re: fclean all
.PHONY: all bonus clean fclean re