NAME = minishell

CC = cc

FLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft-complete

LIBFT_LIB = ${LIBFT_DIR}/libft_complete.a

LIBFT_FLAG = -lft_complete

INCLUDES = -I ./Includes/

EXEC_SOURCES = 	./Exec/

LEXER_SOURCES = 	./Parsing/Lexer/main.c\
					./Parsing/Lexer/lexer.c\
					./Parsing/Lexer/lexer_free.c\
					./Parsing/Lexer/lexer_utils.c

PARSER_SOURCES = 	./Parsing/Parser/

EXEC_OBJS = ${EXEC_SOURCES:.c=.o}

LEXER_OBJS = ${LEXER_SOURCES:.c=.o}

PARSER_OBJS = ${PARSER_SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${LEXER_OBJS} ${PARSER_OBJS} ${EXEC_OBJS} ${LIBFT_LIB}
	${CC} ${FLAGS} \
		${LEXER_OBJS} \
		-L${LIBFT_DIR} -o $@ ${LIBFT_FLAG}

${LIBFT_LIB} :
	${MAKE} -C ${LIBFT_DIR}

%.o : %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${OBJS}

fclean : clean
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
