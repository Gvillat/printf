#include "includes/ft_printf.h"

void 	*ft_arg_p(PF *argument, va_list ap)
{
	void *p;

	ft_buff(argument, "0x");
	p = ft_itoa_base((uintmax_t)(void*)ap, 16);
	p = ft_strlower(p);
	return(ft_buff(argument, (char*)p));
}