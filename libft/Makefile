NAME:= libft.a
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
LIBFT_PATH:= ./
SOURCES:= 	${LIBFT_PATH}/ft_strchr.c\
			${LIBFT_PATH}/ft_memcpy.c\
			${LIBFT_PATH}/ft_isalnum.c\
			${LIBFT_PATH}/ft_isascii.c\
			${LIBFT_PATH}/ft_isdigit.c\
			${LIBFT_PATH}/ft_isprint.c\
			${LIBFT_PATH}/ft_lstiter.c\
			${LIBFT_PATH}/ft_split.c\
			${LIBFT_PATH}/ft_lstclear.c\
			${LIBFT_PATH}/ft_lstnew.c\
			${LIBFT_PATH}/ft_strlcpy.c\
			${LIBFT_PATH}/ft_memcmp.c\
			${LIBFT_PATH}/ft_putchar_fd.c\
			${LIBFT_PATH}/ft_putendl_fd.c\
			${LIBFT_PATH}/ft_striteri.c\
			${LIBFT_PATH}/ft_strjoin.c\
			${LIBFT_PATH}/ft_strlen.c\
			${LIBFT_PATH}/ft_strmapi.c\
			${LIBFT_PATH}/ft_strlcat.c\
			${LIBFT_PATH}/ft_strtrim.c\
			${LIBFT_PATH}/ft_lstadd_back.c\
			${LIBFT_PATH}/ft_tolower.c\
			${LIBFT_PATH}/ft_strnstr.c\
			${LIBFT_PATH}/ft_memchr.c\
			${LIBFT_PATH}/ft_substr.c\
			${LIBFT_PATH}/ft_lstmap.c\
			${LIBFT_PATH}/ft_putstr_fd.c\
			${LIBFT_PATH}/ft_strncmp.c\
			${LIBFT_PATH}/ft_itoa.c\
			${LIBFT_PATH}/ft_memset.c\
			${LIBFT_PATH}/ft_putnbr_fd.c\
			${LIBFT_PATH}/ft_strrchr.c\
			${LIBFT_PATH}/ft_calloc.c\
			${LIBFT_PATH}/ft_lstsize.c\
			${LIBFT_PATH}/ft_strdup.c\
			${LIBFT_PATH}/ft_lstlast.c\
			${LIBFT_PATH}/ft_memmove.c\
			${LIBFT_PATH}/ft_atoi.c\
			${LIBFT_PATH}/ft_lstdelone.c\
			${LIBFT_PATH}/ft_bzero.c\
			${LIBFT_PATH}/ft_isalpha.c\
			${LIBFT_PATH}/ft_lstadd_front.c\
			${LIBFT_PATH}/ft_toupper.c
OBJECTS:= ${SOURCES:.c=.o}
all: ${NAME}
${NAME}: ${OBJECTS}
	ar r $@ $^
%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@
clean:
	rm -f ${OBJECTS}
fclean: clean
	rm -f ${NAME}
re: fclean all
.PHONY: all clean fclean re
