/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:27:38 by almarico          #+#    #+#             */
/*   Updated: 2024/06/19 14:36:01 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX					2147483647
# define INT_MIN					-2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_lmanipulate
{
	t_list	*first;
}				t_lmanipulate;

typedef long long	t_ll;

t_ll			ft_atoll(const char *string);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_lstadd_back(t_list **lst, t_list *neww);
void			ft_lstadd_front(t_list **lst, t_list *neww);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstinit(t_list *list);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strcat(char *dest, const char *src);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
float			ft_atof(const char *string);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *string);
int				ft_atoi_base(char *str, char *base);
int				ft_isalnum(int charactere);
int				ft_isalpha(int charactere);
int				ft_isascii(int c);
int				ft_isdigit(int charactere);
int				ft_isprint(int charactere);
int				ft_isspace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_size(long long int n);
int				ft_count_word(char const *str, char c);
int				ft_count_word_with_string(char const *str,
					char *string_separator);

#endif // !LIBFT_H
