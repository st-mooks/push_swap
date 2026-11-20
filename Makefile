# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 16:02:50 by mbadarin          #+#    #+#              #
#    Updated: 2026/11/19 12:30:56 by mbadarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=				push_swap
BONUS_NAME:=		checker
CC:= 				cc
CFLAGS:=			-Wall -Werror -Wextra
PUSH_SWAP_PATH:= 	.
LIBFT_PATH:=		${PUSH_SWAP_PATH}/libft
MAIN:=				${PUSH_SWAP_PATH}/main.c
SOURCES:=			${PUSH_SWAP_PATH}/simple.c\
					${PUSH_SWAP_PATH}/medium_push.c\
					${PUSH_SWAP_PATH}/medium_utils.c\
					${PUSH_SWAP_PATH}/medium.c\
					${PUSH_SWAP_PATH}/3way_base.c\
					${PUSH_SWAP_PATH}/3way_helpers.c\
					${PUSH_SWAP_PATH}/3way_solve.c\
					${PUSH_SWAP_PATH}/3way_utils.c\
					${PUSH_SWAP_PATH}/a_ops.c\
					${PUSH_SWAP_PATH}/b_ops.c\
					${PUSH_SWAP_PATH}/ab_ops.c\
					${PUSH_SWAP_PATH}/push_swap.c\
					${PUSH_SWAP_PATH}/rotate.c\
					${PUSH_SWAP_PATH}/disorder.c\
					${PUSH_SWAP_PATH}/input_parsing.c\
					${PUSH_SWAP_PATH}/list_functions.c\
					${PUSH_SWAP_PATH}/ops_utils.c\
					${PUSH_SWAP_PATH}/print_utils.c\
					${PUSH_SWAP_PATH}/split_input.c\
					${PUSH_SWAP_PATH}/utils_medium_complex.c\
					${PUSH_SWAP_PATH}/validation.c
BONUS_MAIN:=		${PUSH_SWAP_PATH}/main.c
BONUS_SOURCES:=		${PUSH_SWAP_PATH}/utils.c
OBJECTS:=			${SOURCES:.c=.o}
BONUS_OBJECTS:=		${BONUS_SOURCES:.c=.o}
HEADER:=			push_swap.h
BONUS_HEADER:=		${PUSH_SWAP_PATH}/push_swap_bonus.h
LIBFT:=				${LIBFT_PATH}/libft.a
all: ${NAME}
${NAME}: ${MAIN} ${OBJECTS} ${LIBFT}
	${CC} ${CFLAGS} $^ -L${LIBFT_PATH} -lft -o ${NAME}
${LIBFT}:
	make -C ${LIBFT_PATH}
bonus: ${BONUS_MAIN} ${BONUS_OBJECTS} ${OBJECTS}
	${CC} ${CFLAGS} $^ -L${LIBFT_PATH} -lft -o ${BONUS_NAME}
%.o: %.c ${HEADER} ${BONUS_HEADER}
	${CC} ${CFLAGS} $< -c -o $@
clean:
	make clean -C ${LIBFT_PATH}
	rm -f ${OBJECTS} ${BONUS_OBJECTS}
fclean: clean
	rm -f ${NAME} ${BONUS_NAME} ${LIBFT_PATH}/libft.a
re: fclean all
.PHONY: all bonus clean fclean re