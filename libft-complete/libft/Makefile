# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 15:09:47 by almarico          #+#    #+#              #
#    Updated: 2024/06/19 14:36:17 by almarico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./ft_atof.c\
	./ft_atoi.c\
	./ft_atoi_base.c\
	./ft_atoll.c\
	./ft_bzero.c\
	./ft_calloc.c\
	./ft_count_word.c\
	./ft_count_word_with_string.c\
	./ft_isalnum.c\
	./ft_isalpha.c\
	./ft_isascii.c\
	./ft_isdigit.c\
	./ft_isprint.c\
	./ft_isspace.c\
	./ft_itoa.c\
	./ft_memchr.c\
	./ft_memcmp.c\
	./ft_memcpy.c\
	./ft_memmove.c\
	./ft_memset.c\
	./ft_putchar_fd.c\
	./ft_putendl_fd.c\
	./ft_putnbr_fd.c\
	./ft_putstr_fd.c\
	./ft_split.c\
	./ft_strchr.c\
	./ft_strcmp.c\
	./ft_strdup.c\
	./ft_striteri.c\
	./ft_strjoin.c\
	./ft_strlcat.c\
	./ft_strlcpy.c\
	./ft_strlen.c\
	./ft_strmapi.c\
	./ft_strncmp.c\
	./ft_strnstr.c\
	./ft_strrchr.c\
	./ft_strtrim.c\
	./ft_substr.c\
	./ft_tolower.c\
	./ft_toupper.c\
	./ft_lstadd_back.c\
	./ft_lstadd_front.c\
	./ft_lstclear.c\
	./ft_lstdelone.c\
	./ft_lstinit.c\
	./ft_lstiter.c\
	./ft_lstlast.c\
	./ft_lstmap.c\
	./ft_lstnew.c\
	./ft_lstsize.c

OBJ_PATH = obj/

OBJS = ${addprefix ${OBJ_PATH}, ${SRCS:.c=.o}}

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all: ${OBJ_PATH} ${NAME}

${OBJ_PATH} :
	mkdir ${OBJ_PATH}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

${OBJ_PATH}%.o: %.c
		${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean:
		rm -f ${OBJS}
		rm -rf ${OBJ_PATH}

fclean: clean
		rm -f ${NAME}

re: fclean all
