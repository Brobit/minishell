/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:18:33 by almarico          #+#    #+#             */
/*   Updated: 2023/12/17 14:25:53 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>

# define TABLEAU_LOW_HEX "0123456789abcdef"
# define TABLEAU_UPP_HEX "0123456789ABCDEF"
# define TABLEAU_DEC "0123456789"

typedef struct s_flag
{
	int	middlescore;
	int	zero;
	int	space;
	int	plus;
	int	diese;
	int	precision;
}				t_flag;

typedef struct s_width
{
	ssize_t	width;
	ssize_t	precision;
}				t_width;

typedef struct s_specifier
{
	char	specifier;
}				t_specifier;

int		ft_printf(const char *str, ...);
void	ft_init(t_flag *flag, t_width *length, t_specifier *the);
void	ft_chparam(const char **s, t_width *len, t_specifier *the, t_flag *f);
void	ft_check_conflict(t_specifier *the, t_width *length, t_flag *flag);
void	ft_set_specifier_c(t_flag *flag, t_width *length);
void	ft_set_specifier_s(t_flag *flag);
void	ft_set_specifier_p(t_flag *flag, t_width *length);
void	ft_set_specifier_d(t_flag *flag);
void	ft_set_specifier_i(t_flag *flag);
void	ft_set_specifier_u(t_flag *flag);
void	ft_set_specifier_x(t_flag *flag);
void	ft_set_specifier_uppx(t_flag *flag);
void	ft_set_specifier_modulo(t_flag *flag, t_width *length);
void	ft_write_char(int c, size_t *char_counter, t_flag *flag, t_width *len);
void	ft_write_str(char *str, size_t *char_c, t_flag *flag, t_width *length);
void	ft_w_pointer(uintptr_t p, size_t *char_c, t_flag *flag, t_width *len);
void	ft_w_integer(int integer, size_t *char_c, t_width *len, t_flag *flag);
void	ft_w_uint(unsigned int integer, size_t *cc, t_width *len, t_flag *f);
void	ft_putnbr_base(long int nbr, char *base);
void	ft_putnbr_base_hex(long int nbr, char *base, size_t *char_counter);
size_t	ft_w_hex(unsigned int n, t_specifier *the, t_flag *flag, t_width *len);
size_t	ft_write_param(va_list ap, t_specifier *the, t_flag *f, t_width *len);
size_t	ft_write_space(int len, int stopper);
size_t	ft_write_zero(int len, int stopper);
size_t	ft_size_addr(uintptr_t addr);

#endif // !FT_PRINTF_H
