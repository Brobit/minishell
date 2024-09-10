# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 13:39:09 by almarico          #+#    #+#              #
#    Updated: 2024/01/20 11:54:21 by almarico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = ft_conflit_checker.c \
	  ft_init.c \
	  ft_flag_writer.c \
	  ft_param_checker.c \
	  ft_param_writer.c \
	  ft_printf.c \
	  ft_putnbr_base.c \
	  ft_putnbr_base_hex.c \
	  ft_set_specifier_1.c \
	  ft_set_specifier_2.c \
	  ft_write_char.c \
	  ft_write_hex.c \
	  ft_write_integer.c \
	  ft_write_pointer.c \
	  ft_write_str.c

OBJ_PATH = obj/

OBJ = ${addprefix ${OBJ_PATH}, ${SRC:.c=.o}}

all : ${OBJ_PATH} ${NAME}

${OBJ_PATH} :
	mkdir ${OBJ_PATH}

${NAME} : ${OBJ}
	ar rs ${NAME} ${OBJ}

${OBJ_PATH}%.o : %.c
	${CC} ${FLAGS} -c $< -o $@

clean :
	rm -f ${OBJ}
	rm -rf ${OBJ_PATH}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
