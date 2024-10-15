NAME = minishell

CC = cc

FLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft-complete

LIBFT_LIB = ${LIBFT_DIR}/libft_complete.a

LIBFT_FLAG = -lft_complete

OTHER_FLAG = -lreadline

INCLUDES = -I ./Includes/

EXEC_SOURCES = 	./Exec/Builtin/ft_cd.c\
				./Exec/Builtin/ft_echo.c\
				./Exec/Builtin/ft_export.c\
				./Exec/Builtin/ft_env.c\
				./Exec/Builtin/ft_unset.c\
				./Exec/Builtin/ft_exit.c\
				./Exec/ft_exec.c\
				./Exec/exec_utils.c\
				./Exec/linkedlist_utils.c\
				./Exec/linkedlist_utils2.c\
				./Exec/here_doc.c\


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
					./Parsing/Parser/check_syntax.c\
					./Parsing/Parser/redirection_utils.c\
					./Parsing/Parser/parser_free.c\
					./Parsing/Parser/env_variable.c\
					./Parsing/Parser/quotes.c\
					./Parsing/Parser/double_quotes.c\
					./Parsing/Parser/split_input.c

EXEC_OBJS = ${EXEC_SOURCES:.c=.o}

LEXER_OBJS = ${LEXER_SOURCES:.c=.o}

PARSER_OBJS = ${PARSER_SOURCES:.c=.o}

OBJS = ${LEXER_OBJS} ${PARSER_OBJS} ${EXEC_OBJS}

all : ${NAME}

${NAME} : ${LEXER_OBJS} ${PARSER_OBJS} ${EXEC_OBJS} ${LIBFT_LIB}
	${CC} ${FLAGS} -g \
		${LEXER_OBJS} \
		${PARSER_OBJS} \
		${EXEC_OBJS}\
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
