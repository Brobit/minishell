/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:31:26 by almarico          #+#    #+#             */
/*   Updated: 2024/09/27 10:52:47 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft-complete/libft/libft.h"
# include "../libft-complete/printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>

# define SUCCESS			0
# define FAIL				1

/* error define */

# define ERR_ARGC			"too much argument to launch minishell ! "
# define ERR_ENV_COPY		"an error occur while malloc for env copy "
# define ERR_ENV_DUP		"an error occur while copying the environment "

/* structures */

typedef struct s_env
{
	char	**env;
}				t_env;

typedef enum e_redirection_type
{
	NONE,
	INPUT,
	OUTPUT,
	HERE_DOC,
	APPEND,
}			t_redirection_type;

typedef struct s_redirection
{
	t_redirection_type			type;
	const char					*payload;
	struct s_redirection		*next;
}				t_redirection;

typedef struct s_exec
{
	t_redirection				*redirection_list;
	char						*cmd;
	char						**option;
	struct s_exec				*next;
}				t_exec;

/* lexer.c */

int							lexer_entry(char **env);

/* lexer_free.c */

void						free_env(t_env *copy);
void						free_readline(void);

/* lexer_utils.c */

void						error(char *msg);

/* signal_handler.c */

int							init_signal(struct sigaction *signal, int sigerror);

/* stdin_listener.c */

void						stdin_listener(t_env *copy);

/* parser_entry.c */

int							parser_entry(char *input, t_env *copy);

/* exec_list.c */

t_exec						*list_new_node(void);
t_exec						*list_last(t_exec *lst);
void						list_add_back(t_exec **exec, t_exec *neww);

/* parser_functions.c */

t_redirection				*get_redirections(char *instruction_line);
void						trim_redirections(char **line);
char						*get_command(char *instruction_line);
char						**get_option(char *instruction_line);

/* redirection_lis.c */

t_redirection				*redirection_list_new_node(void);
t_redirection				*redirection_list_last(t_redirection *lst);
void						redirection_list_add_back(t_redirection **exec, \
							t_redirection *neww);

/* check_syntax.c */

int							check_syntax_error(char *input);

/* redirection_utils.c */

int							fill_redirection(t_redirection *redirection_list, \
							char *instruction_line);

/* parser_free.c */

void						free_instructions(char **instructions);

/* env_variable_and_quotes */

void						check_env_variable_and_quotes(char **input, t_env *copy);

#endif // !MINISHELL_H
