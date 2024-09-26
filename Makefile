NAME = minishell

CC = cc

FLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft-complete

LIBFT_LIB = ${LIBFT_DIR}/libft_complete.a

LIBFT_FLAG = -lft_complete

OTHER_FLAG = -lreadline

INCLUDES = -I ./Includes/

EXEC_SOURCES = 	./Exec/

LEXER_SOURCES = 	./Parsing/Lexer/main.c\
					./Parsing/Lexer/lexer.c\
					./Parsing/Lexer/lexer_free.c\
					./Parsing/Lexer/lexer_utils.c\
					./Parsing/Lexer/signal_handler.c\
					./Parsing/Lexer/stdin_listener.c

PARSER_SOURCES = 	./Parsing/Parser/parser_entry.c\
					./Parsing/Parser/exec_list.c\
					./Parsing/Parser/parser_functions.c\
					./Parsing/Parser/redirection_list.c\
					./Parsing/Parser/chech_syntax.c\
					./Parsing/Parser/redirection_utils.c\
					./Parsing/Parser/parser_free.c

EXEC_OBJS = ${EXEC_SOURCES:.c=.o}

LEXER_OBJS = ${LEXER_SOURCES:.c=.o}

PARSER_OBJS = ${PARSER_SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${LEXER_OBJS} ${PARSER_OBJS} ${EXEC_OBJS} ${LIBFT_LIB}
	${CC} ${FLAGS} \
		${LEXER_OBJS} \
		${PARSER_OBJS} \
		-L${LIBFT_DIR} -o $@ ${LIBFT_FLAG} ${OTHER_FLAG}

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
