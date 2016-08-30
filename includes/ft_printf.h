#ifndef FT_PRINTF
# define FT_PRINTF
# define PF t_printf
# define SPE t_spec
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

char g_buff[4096];
int  g_i;

/*
** fla[13] is an array which contains flags for precision, width, flags
** and modifiers such as:
** |0        |1    |2|3|4|5|6|7 |8|9 |10|11|12|
** |precision|width|#|0|-|+| |hh|h|ll|l |j |z |
*/

// %[flags][width][.precision][length]specifier 
// specifier : s S p d D i o O u U x X c C

typedef struct s_printf t_printf;
typedef struct s_spec t_spec;
struct s_printf
{
	char *format;
	int ret;
	int index;
	char spec;
	int flags[13];
	char *arg;
};

struct s_spec
{
	char c;
	void* (*ptr)(void *, void *);
};

void 	ft_init_buff();
int	 	ft_display(PF *argument);
int		ft_get_flags(PF *argument, va_list apg);
int		ft_check_flags(PF *argument);
int		ft_check_width(PF *argument);
int		ft_check_precision(PF *argument);
int		ft_check_length(PF *argument);
int		ft_check_spec(PF *argument);
#endif 