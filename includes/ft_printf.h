/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:36:12 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:36:13 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF t_printf
# define SPE t_spec
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <wchar.h>

char	g_buff[4096];
int		g_i;

/*
** fla[13] is an array which contains flags for precision, width, flags
** and modifiers such as:
** |0        |1    |2|3|4|5|6|7 |8|9 |10|11|12|
** |precision|width|#|0|-|+| |hh|h|ll|l |j |z |
** %[flags][width][.precision][length]specifier
** specifier : s S p d D i o O u U x X c C
*/

typedef struct s_printf	t_printf;
typedef struct s_spec	t_spec;

struct	s_printf
{
	char			*format;
	int				ret;
	size_t			index;
	unsigned char	spec;
	int				flags[13];
	char			*arg;
	int				zeropadding;
	int				rightpadding;
};

struct	s_spec
{
	int (*spe[128])(PF*, va_list);
};

void	ft_init_buff();
PF		*ft_init_argument(PF *argument);
void	ft_init_spe_tab(SPE *spe);

int		signed_handler(PF *argument, va_list ap);
int		pointer_handler(PF *argument, va_list ap);
int		character_handler(PF *argument, va_list ap);
int		string_handler(PF *argument, va_list ap);
int		unsigned_handler(PF *argument, va_list ap);
int		ft_arg_nospe(PF *argument, va_list ap);
int		prc_handler(PF *argument, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_display(PF *argument);
void	*ft_buff(char *str);
int		ft_print_character(PF *argument, char *c);
int		ft_print_str(PF *argument, char *s);
int		ft_print_wstr(PF *argument, char *s);
int		ft_print_number(PF *argument, char *pre, char *s);

void	*ft_strlower(char *s);
char	*ft_itoa_base(uintmax_t nbr, int base);
int		ft_wchartostr(char *s, wchar_t wc);
void	ft_nputchar(char c, ssize_t n);
size_t	ft_wstrlen(wchar_t *s);
int		ft_wstrtostr(char *s, wchar_t *wstr, int n);

int		ft_check_flags(PF *argu);
int		ft_check_width(PF *argu);
int		ft_check_precision(PF *argument);
void	ft_check_length(PF *argu);
int		ft_check_spec(PF *argument);
int		ft_check_spec_bis(PF *argument);

int		ft_get_flags(PF *argu);

#endif
