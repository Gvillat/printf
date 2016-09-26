#include "../includes/ft_printf.h"


int			pointer_handler(PF *argument, va_list ap)
{
	uintmax_t	n;
	char		*s;

	n = va_arg(ap, uintmax_t);
	if (!(s = ft_strlower(ft_itoa_base(n, 16))))
		return (-1);
	return (ft_print_number(argument, "0x", s));
}

int prc_handler(PF *argument, va_list ap)
{
	ft_print_character(argument, "%");
	return(0);
}