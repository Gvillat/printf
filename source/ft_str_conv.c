#include "../includes/ft_printf.h"

void *ft_arg_s(PF *argument, va_list ap)
{
	char *str;
	wchar_t *res;

	if (argument->flags[10] == 1)
	{
		res = (wchar_t*)ap;
		return(ft_apply_flags(res, argument, ap));
	}
	else
	{
		str = (char*)ap;
		return(ft_apply_flags(str, argument, ap));
	}
}