#include "includes/ft_printf.h"

void *ft_arg_d(void *argument, va_list ap)
{
	char *str;

	str = ft_itoa_base((uintmax_t)ap, 10);
	return(ft_buff(argument, str));
}