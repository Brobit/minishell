# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 13:27:16 by almarico          #+#    #+#              #
#    Updated: 2023/12/18 13:35:35 by almarico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS = get_next_line.c\
	   get_next_line_utils.c\
	   get_next_line_bonus.c\
	   get_next_line_utils_bonus.c

OBJ_PATH = obj/

OBJS = ${addprefix ${OBJ_PATH}, ${SRCS:.c=.o}}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all : ${OBJ_PATH} ${NAME}

${OBJ_PATH} :
	mkdir ${OBJ_PATH}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

${OBJ_PATH}%.o : %.c
	${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean :
	rm -rf ${OBJS}
	rm -rf ${OBJ_PATH}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
