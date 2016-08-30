#include "includes/ft_printf.h"

void *ft_arg_d(void *argument, va_list ap)
{
	char *str;

	if (argument->flags[])
	str = ft_itoa_base((uintmax_t)ap, 10);
	return(ft_buff(argument, str));
}

void 	*ft_arg_upd(void * , va_list)
{
	return(ft_buff(argument, str));
}

void 	*ft_arg_nospe(void * , va_list)
{

}

void 	*ft_arg_prc(void *, va_list)
{

}