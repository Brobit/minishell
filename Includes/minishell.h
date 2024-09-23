/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:31:26 by almarico          #+#    #+#             */
/*   Updated: 2024/09/18 00:13:50 by hehuang          ###   ########.fr       */
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

/* lexer.c */

int							lexer_entry(char **env);

/* lexer_free.c */

void						free_env(t_env *copy);

/* lexer_utils.c */

void						error(char *msg);

/* exec */
void						echo_msg(char **msg);
void						ft_cd(char *path);
void						ft_pwd(void);
void						ft_export(char **env);
void						ft_env(char **env);
void						ft_unset(char	**env, char *my_var);

/* exec_utils.c */

char						*ft_get_path(char	*cmd, char	**envp);
char						**copy_tab(char	**env, int *size);
void            remove_element(char **tab, int index);


/*exec test
void						ft_cd(char *path, char *cmd, char **envp);
*/
#endif // !MINISHELL_H
