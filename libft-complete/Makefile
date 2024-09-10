NAME = libft_complete.a
LIB_GNL = get_next_line/gnl.a
LIB_PRINTF = printf/libftprintf.a
LIB_LIBFT = libft/libft.a

all : ${NAME}

${NAME} : ${LIB_GNL} ${LIB_PRINTF} ${LIB_LIBFT}
	echo "CREATE ${NAME}\nADDLIB ${LIB_GNL}\nADDLIB ${LIB_PRINTF}\nADDLIB ${LIB_LIBFT}\nSAVE\nEND" | ar -M

${LIB_GNL} :
	${MAKE} -C $$(dirname $@)

${LIB_PRINTF} :
	${MAKE} -C $$(dirname $@)

${LIB_LIBFT} :
	${MAKE} -C $$(dirname $@)

clean :
	${MAKE} clean -C $$(dirname ${LIB_PRINTF});
	${MAKE} clean -C $$(dirname ${LIB_GNL});
	${MAKE} clean -C $$(dirname ${LIB_LIBFT});

fclean : clean
	${RM} ${LIB_PRINTF} ${LIB_GNL} ${LIB_LIBFT} ${NAME}

re : fclean all

.PHONY : all clean fclean re
