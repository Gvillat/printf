#include "includes/ft_printf.h"

void *ft_arg_s(void *argument, va_list ap)
{
	char *str;

	str = (char*)ap;
	return(ft_buff(argument, str));
}

// void 	*ft_arg_ups(void * , va_list)
// {
// 	return(ft_buff(argument, str));
// }
