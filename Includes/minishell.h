/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:31:26 by almarico          #+#    #+#             */
/*   Updated: 2024/11/24 15:19:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft-complete/libft/libft.h"
# include "../libft-complete/printf/ft_printf.h"
# include "../libft-complete/get_next_line/gnl.h"
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

# define EXIT_NO_NUM_ERR	"exit : numeric argument required\n"
# define EXIT_ARGS_ERROR	"exit : too many arguments\n"
# define ERR_CMD_NOT_FOUND	" : command not found\n"

/* gobale variable */

extern volatile int			g_exit_status;

/* structures */

typedef struct s_env_list
{
	struct s_env_list	*next;
	struct s_env_list	*prev;
	char				*name;
	char				*val;
	struct s_env		*env;
}				t_env_list;

typedef struct s_env
{
	char					**env;
	int						last_status;
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
	int							not_null;
	struct s_redirection		*next;
}				t_redirection;

typedef struct s_exec
{
	t_redirection				*redirection_list;
	char						*cmd;
	char						**option;
	struct s_exec				*next;
}				t_exec;

typedef struct s_exec_list
{
	struct s_exec		*exec;
	struct s_exec_list	*next;
	struct s_exec_list	*prev;
	int					pipe_fd[2];
	pid_t				pid;
	const char			*outfile;
	const char			*infile;
	int					fd_in;
	int					fd_out;
	char				*cmd;
	char				**args;
	int					cancel;
	t_redirection		*redirec_list;
}				t_exec_list;

/* lexer.c */

int							lexer_entry(char **env);

/* lexer_free.c */

void						free_env(t_env *copy);
void						free_readline(void);

/* lexer_utils.c */

void						error(char *msg);

/* signal_handler.c */

void						setup_signal(int state);

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
char						*get_command(char *instruction_line, t_env *copy);
char						**get_option(char *instruction_line, t_env *copy);

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
void						search_and_replace_env_variable(char **input, \
							t_env *copy);
void						transform_string(char **input, t_env *copy, int *i);

/* quotes.c */

int							is_in_quotes(char *str, int i);
int							is_interpreted(char *str, int i);

/* double_quotes.c */

int							is_in_double_quotes(char *str, int i);

/* split_input.c */

char						**split_input(char const *s, char c);

/* builtin */
void						ft_echo(t_exec_list *exec);
void						ft_cd(char **path, t_env_list **env);
void						ft_pwd(void);
void						ft_export(t_env_list **env, char **args);
/* env */
void						ft_env(t_env_list *env);
void						update_env(t_env_list **env);
t_env_list					*find_env(t_env_list **head, char *name, int *plus);
void						append_val(t_env_list **elmt, char	*app_val, \
							t_env_list **head);
int							valid_name(char *name);
/* end env */
void						ft_unset(t_env_list	**env, char **my_var);
void						ft_exec(t_exec *exec, t_env *env);
void						ft_exit(t_exec_list *exec, t_env_list *env);
/* end builtin */
/* exec */

/* heredoc */

int							ft_here_doc(const char *delimiter);
void						del_curr_heredoc(void);

/* exec_utils.c */

char						*ft_get_path(char	*cmd, t_env_list	**envp);
char						**copy_tab(char	**env, int *size);
int							ft_strchr_pos(const char *s, int c);
int							count_params(char	**params);
char						**list_to_char(t_env_list **env);

int							check_redirection(t_exec_list **exec);
void						dup_in_out(t_exec_list *exec);
void						check_pipe(t_exec **exec, int in_parent, \
											int fd_last_pipe, int *pipe_fd);
/* linkedlist_utils 1 & 2*/

t_env_list					*new_env(char *name, char *value, t_env_list *prev);
void						add_end(t_env_list **env, t_env_list *new_elmt);
void						rm_elmt(t_env_list **env, t_env_list *elmt);
t_env_list					*find_elmt(t_env_list **env, char	*elmt);
t_env_list					*create_list_from_tab(char **env);
int							list_size(t_env_list *mylist);
void						free_list(t_env_list *list);
void						free_elmt(t_env_list **elmt);
t_env_list					*copy_list(t_env_list *env);
int							set_value(t_env_list **env, char *str);

/* EXEC NODE LIST (DOUBLE LINKED LIST)*/

t_exec_list					*get_exec_list(t_exec *exec);

/* trim_quotes.c */

void						is_a_quote(char c, int *state);
void						trim_quotes(char **option, t_env *copy);
void						trim_command_quotes(char *cmd, t_env *copy);
void						trim_payload_quotes(char *option);

/* free_exec_list.c */

void						free_exec_list(t_exec **exec);

/* check_quotes.c */

int							check_quotes(char *input);

/* env_variable_utils.c */

char						*keep_intact(char **input, int *i);
int							is_in_set_to_keep(char c);

/* ft_free_exec.c */

void						ft_free_str_list(char **str_list);
void						free_all_exit(t_exec_list *exec, t_env_list *env, \
								int exit_code);
void						free_child(char	**str_tab, t_exec_list *exec_list, \
								t_env_list *env_list, t_exec *exec);
void						close_all_fd(t_exec_list	**exec);
int							exec_builtin(t_exec_list *exec, t_env_list **env, \
								int in_child);
void						solo_builtins(t_exec_list *exec, t_env_list **env);

/* DEBUG */
char						**add_str(char **tab, char *elmt);
void						display_exec(t_exec_list *exec);
void						ft_close(int fd, const char *filename, \
								int pipe_entry);
int							ft_open(const char	*name, int trunc, int append);
int							check_builtin(t_exec_list *exec);
char						**get_args(t_exec *exec);
void						replace_abs_path(char	**str, t_env_list **env);
t_exec_list					*verif_exec(t_exec_list	*exec, t_env_list **env);

//# define close(X) printf("CLOSE: %d\n", X); close(X)

#endif // !MINISHELL_H
