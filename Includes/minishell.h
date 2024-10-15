/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:31:26 by almarico          #+#    #+#             */
/*   Updated: 2024/10/15 12:53:02 by hehuang          ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/types.h>


# define SUCCESS			0
# define FAIL				1
# define TRUE				1
# define FALSE				0

# define TLL_MAX			9223372036854775807ULL
/* error define */

# define ERR_ARGC			"too much argument to launch minishell ! "
# define ERR_ENV_COPY		"an error occur while malloc for env copy "
# define ERR_ENV_DUP		"an error occur while copying the environment "

/* gobale variable */

extern volatile int			g_exit_status;

/* structures */

typedef struct s_env_list
{
	struct s_env_list	*next;
	struct s_env_list	*prev;
	char				*name;
	char				*val;
}				t_env_list;

typedef struct s_env
{
	char					**env;
	struct s_env_list		*head;
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

typedef struct s_array
{
	char			*str;
	struct s_array	*next;
}				t_array;

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
void						exec_trim(char **line, char **res, int *i, int j);

/* parser_free.c */

void						free_instructions(char **instructions);

/* env_variable */

void						check_env_variable_and_quotes(char **input, \
							t_env *copy);

/* quotes.c */

int							is_in_quotes(char *str, int i);
int							is_interpreted(char *str, int i);

/* double_quotes.c */

int							is_in_double_quotes(char *str, int i);

/* split_input.c */

char						**split_input(char const *s, char c);

/* builtin */
void						ft_echo(char **msg);
void						ft_cd(char **path, t_env_list **env);
void						ft_pwd(void);
void						ft_export(t_env_list **env, char **args);
void						ft_env(t_env_list *env);
void						ft_unset(t_env_list	**env, char **my_var);
void						ft_exec(t_exec *exec, t_env *env);
void						ft_exit(char **exit_code);

/* exec */

/* heredoc */

void						ft_here_doc(const char *delimiter);

/* exec_utils.c */

char						*ft_get_path(char	*cmd, t_env_list	**envp);
char						**copy_tab(char	**env, int *size);
int							ft_strchr_pos(const char *s, int c);
int							count_params(char	**params);
char						**list_to_char(t_env_list **env);

/* linkedlist_utils 1 & 2*/

t_env_list					*new_env(char *name, char *value, t_env_list *prev);
void						add_end(t_env_list **env, t_env_list *new_elmt);
void						rm_elmt(t_env_list **env, t_env_list *elmt);
t_env_list					*find_elmt(t_env_list **env, char	*elmt);
t_env_list					*create_list_from_tab(char **env);
int							list_size(t_env_list *mylist);
void						free_list(t_env_list **list);
void						free_elmt(t_env_list **elmt);
t_env_list					*copy_list(t_env_list *env);
int							set_value(t_env_list **env, char *str, char *val);

#endif // !MINISHELL_H
